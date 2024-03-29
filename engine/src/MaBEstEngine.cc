/* 
   MaBoSS (Markov Boolean Stochastic Simulator)
   Copyright (C) 2011 Institut Curie, 26 rue d'Ulm, Paris, France
   
   MaBoSS is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
   
   MaBoSS is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
   
   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA 
*/

/*
   Module:
     MaBEstEngine.cc

   Authors:
     Eric Viara <viara@sysra.com>
     Gautier Stoll <gautier.stoll@curie.fr>
 
   Date:
     January-March 2011
*/

#include "MaBEstEngine.h"
#include "Probe.h"
#include <stdlib.h>
#include <math.h>
#include <iomanip>

const std::string MaBEstEngine::VERSION = "2.0";
size_t RandomGenerator::generated_number_count = 0;

MaBEstEngine::MaBEstEngine(Network* network, RunConfig* runconfig) :
  network(network), time_tick(runconfig->getTimeTick()), max_time(runconfig->getMaxTime()), sample_count(runconfig->getSampleCount()), discrete_time(runconfig->isDiscreteTime()), thread_count(runconfig->getThreadCount()) {

  tid = NULL;

  if (thread_count > 1 && !runconfig->getRandomGeneratorFactory()->isThreadSafe()) {
    std::cerr << "Warning: non reentrant random, may not work properly in multi-threaded mode\n";
  }
  network->updateRandomGenerator(runconfig);

  const std::vector<Node*>& nodes = network->getNodes();
  std::vector<Node*>::const_iterator begin = nodes.begin();
  std::vector<Node*>::const_iterator end = nodes.end();

  NetworkState internal_state;
  bool has_internal = false;
  refnode_count = 0;
  while (begin != end) {
    Node* node = *begin;
    if (node->isInternal()) {
      has_internal = true;
      internal_state.setNodeState(node, true);
    }
    if (node->isReference()) {
      reference_state.setNodeState(node, node->getReferenceState());
      refnode_count++;
    }
    ++begin;
  }

  merged_cumulator = NULL;
  cumulator_v.resize(thread_count);
  unsigned int count = sample_count / thread_count;
  unsigned int firstcount = count + sample_count - count * thread_count;
  for (unsigned int nn = 0; nn < thread_count; ++nn) {
    Cumulator* cumulator = new Cumulator(runconfig->getTimeTick(), runconfig->getMaxTime(), (nn == 0 ? firstcount : count));
    if (has_internal) {
#ifdef USE_BITSET
      NetworkState_Impl state2 = ~internal_state.getState();
      cumulator->setOutputMask(state2);
#else
      cumulator->setOutputMask(~internal_state.getState());
#endif
    }
    cumulator_v[nn] = cumulator;
  }
}

NodeIndex MaBEstEngine::getTargetNode(RandomGenerator* random_generator, const MAP<NodeIndex, double>& nodeTransitionRates, double total_rate) const
{
  double U_rand2 = random_generator->generate();
  if (U_rand2 < 1.0e-5) {
    std::cout << "U_rand2 = " << U_rand2 << "\n";
  }
  double random_rate = U_rand2 * total_rate;
  MAP<NodeIndex, double>::const_iterator begin = nodeTransitionRates.begin();
  MAP<NodeIndex, double>::const_iterator end = nodeTransitionRates.end();
  NodeIndex node_idx = INVALID_NODE_INDEX;
  // if (random_rate < 1.0e-5) {  // debugging
  //   std::cout << "random_rate = " << random_rate << "\n";
  // }
  while (begin != end && random_rate >= 0.) {   // need to have ">= 0" for Windows/MinGW PRNG
    node_idx = (*begin).first;
    double rate = (*begin).second;
    random_rate -= rate;
    ++begin;
  }

  assert(node_idx != INVALID_NODE_INDEX);
  assert(network->getNode(node_idx)->getIndex() == node_idx);
  return node_idx;
}

double MaBEstEngine::computeTH(const MAP<NodeIndex, double>& nodeTransitionRates, double total_rate) const
{
  if (nodeTransitionRates.size() == 1) {
    return 0.;
  }

  MAP<NodeIndex, double>::const_iterator begin = nodeTransitionRates.begin();
  MAP<NodeIndex, double>::const_iterator end = nodeTransitionRates.end();
  double TH = 0.;
  double rate_internal = 0.;

  while (begin != end) {
    NodeIndex index = (*begin).first;
    double rate = (*begin).second;
    if (network->getNode(index)->isInternal()) {
      rate_internal += rate;
    }
    ++begin;
  }

  double total_rate_non_internal = total_rate - rate_internal;

  begin = nodeTransitionRates.begin();

  while (begin != end) {
    NodeIndex index = (*begin).first;
    double rate = (*begin).second;
    if (!network->getNode(index)->isInternal()) {
      double proba = rate / total_rate_non_internal;
      TH -= log2(proba) * proba;
    }
    ++begin;
  }

  return TH;
}

struct ArgWrapper {
  MaBEstEngine* mabest;
  unsigned int start_count_thread;
  unsigned int sample_count_thread;
  Cumulator* cumulator;
  RandomGeneratorFactory* randgen_factory;
  int seed;
  STATE_MAP<NetworkState_Impl, unsigned int>* fixpoint_map;
  std::ostream* output_traj;

  ArgWrapper(MaBEstEngine* mabest, unsigned int start_count_thread, unsigned int sample_count_thread, Cumulator* cumulator, RandomGeneratorFactory* randgen_factory, int seed, STATE_MAP<NetworkState_Impl, unsigned int>* fixpoint_map, std::ostream* output_traj) :
    mabest(mabest), start_count_thread(start_count_thread), sample_count_thread(sample_count_thread), cumulator(cumulator), randgen_factory(randgen_factory), seed(seed), fixpoint_map(fixpoint_map), output_traj(output_traj) { }
};

void* MaBEstEngine::threadWrapper(void *arg)
{
  ArgWrapper* warg = (ArgWrapper*)arg;
  try {
    warg->mabest->runThread(warg->cumulator, warg->start_count_thread, warg->sample_count_thread, warg->randgen_factory, warg->seed, warg->fixpoint_map, warg->output_traj);
  } catch(const BNException& e) {
    std::cerr << e;
  }
  return NULL;
}

void MaBEstEngine::runThread(Cumulator* cumulator, unsigned int start_count_thread, unsigned int sample_count_thread, RandomGeneratorFactory* randgen_factory, int seed, STATE_MAP<NetworkState_Impl, unsigned int>* fixpoint_map, std::ostream* output_traj)
{
  const std::vector<Node*>& nodes = network->getNodes();
  std::vector<Node*>::const_iterator begin = nodes.begin();
  std::vector<Node*>::const_iterator end = nodes.end();
  unsigned int stable_cnt = 0;
  NetworkState network_state; 

  RandomGenerator* random_generator = randgen_factory->generateRandomGenerator(seed);
  for (unsigned int nn = 0; nn < sample_count_thread; ++nn) {
    random_generator->setSeed(seed+start_count_thread+nn);
    cumulator->rewind();
    network->initStates(network_state);
    double tm = 0.;
    unsigned int step = 0;
    if (NULL != output_traj) {
      (*output_traj) << "\nTrajectory #" << (nn+1) << '\n';
      (*output_traj) << " istate\t";
      network_state.displayOneLine(*output_traj, network);
      (*output_traj) << '\n';
    }
    while (tm < max_time) {
      double total_rate = 0.;
      MAP<NodeIndex, double> nodeTransitionRates;
      begin = nodes.begin();

      while (begin != end) {
      	Node* node = *begin;
      	NodeIndex node_idx = node->getIndex();
      	if (node->getNodeState(network_state)) {
	        double r_down = node->getRateDown(network_state);
	        if (r_down != 0.0) {
	          total_rate += r_down;
	          nodeTransitionRates[node_idx] = r_down;
	        }
	      } else {
	        double r_up = node->getRateUp(network_state);
	        if (r_up != 0.0) {
	          total_rate += r_up;
	          nodeTransitionRates[node_idx] = r_up;
	        }
	      }
	      ++begin;
      }
      if (total_rate == 0.0) {
      	// may have several fixpoint maps
	      if (fixpoint_map->find(network_state.getState()) == fixpoint_map->end()) {
	        (*fixpoint_map)[network_state.getState()] = 1;
	      } else {
	        (*fixpoint_map)[network_state.getState()]++;
	      }
      	cumulator->cumul(network_state, max_time, 0.);
	      tm = max_time;
	      stable_cnt++;
	      break;
      }

      double transition_time ;
      if (discrete_time) {
	      transition_time = time_tick;
      } else {
	      double U_rand1 = random_generator->generate();
      	transition_time = -log(U_rand1) / total_rate;
      }

      tm += transition_time;

      NodeIndex node_idx = getTargetNode(random_generator, nodeTransitionRates, total_rate);
      double TH = computeTH(nodeTransitionRates, total_rate);

      if (NULL != output_traj) {
	      (*output_traj) << std::setprecision(10) << tm << '\t';
      	network_state.displayOneLine(*output_traj, network);
	      (*output_traj) << '\t' << TH << '\n';
      }

      cumulator->cumul(network_state, tm, TH);

      if (tm >= max_time) {
	      break;
      }

      network_state.flipState(network->getNode(node_idx));
      step++;
    }
    cumulator->trajectoryEpilogue();
  }
  delete random_generator;
}

void MaBEstEngine::run(std::ostream* output_traj)
{
  tid = new pthread_t[thread_count];
  RandomGeneratorFactory* randgen_factory = RunConfig::getInstance()->getRandomGeneratorFactory();
  int seed = RunConfig::getInstance()->getSeedPseudoRandom();
  unsigned int start_sample_count = 0;
  Probe probe;
  for (unsigned int nn = 0; nn < thread_count; ++nn) {
    STATE_MAP<NetworkState_Impl, unsigned int>* fixpoint_map = new STATE_MAP<NetworkState_Impl, unsigned int>();
    fixpoint_map_v.push_back(fixpoint_map);
    ArgWrapper* warg = new ArgWrapper(this, start_sample_count, cumulator_v[nn]->getSampleCount(), cumulator_v[nn], randgen_factory, seed, fixpoint_map, output_traj);
    pthread_create(&tid[nn], NULL, MaBEstEngine::threadWrapper, warg);
    arg_wrapper_v.push_back(warg);

    start_sample_count += cumulator_v[nn]->getSampleCount();
  }
  for (unsigned int nn = 0; nn < thread_count; ++nn) {
    pthread_join(tid[nn], NULL);
  }
  probe.stop();
  elapsed_core_runtime = probe.elapsed_msecs();
  user_core_runtime = probe.user_msecs();
  probe.start();
  epilogue();
  probe.stop();
  elapsed_epilogue_runtime = probe.elapsed_msecs();
  user_epilogue_runtime = probe.user_msecs();
}  

STATE_MAP<NetworkState_Impl, unsigned int>* MaBEstEngine::mergeFixpointMaps()
{
  if (1 == fixpoint_map_v.size()) {
    return new STATE_MAP<NetworkState_Impl, unsigned int>(*fixpoint_map_v[0]);
  }

  STATE_MAP<NetworkState_Impl, unsigned int>* fixpoint_map = new STATE_MAP<NetworkState_Impl, unsigned int>();
  std::vector<STATE_MAP<NetworkState_Impl, unsigned int>*>::iterator begin = fixpoint_map_v.begin();
  std::vector<STATE_MAP<NetworkState_Impl, unsigned int>*>::iterator end = fixpoint_map_v.end();
  while (begin != end) {
    STATE_MAP<NetworkState_Impl, unsigned int>* fp_map = *begin;
    STATE_MAP<NetworkState_Impl, unsigned int>::const_iterator b = fp_map->begin();
    STATE_MAP<NetworkState_Impl, unsigned int>::const_iterator e = fp_map->end();
    while (b != e) {
      NetworkState_Impl state = (*b).first;
      if (fixpoint_map->find(state) == fixpoint_map->end()) {
	      (*fixpoint_map)[state] = (*b).second;
      } else {
	      (*fixpoint_map)[state] += (*b).second;
      }
      ++b;
    }
    ++begin;
  }
  return fixpoint_map;
}

void MaBEstEngine::epilogue()
{
  merged_cumulator = Cumulator::mergeCumulators(cumulator_v);
  merged_cumulator->epilogue(network, reference_state);

  STATE_MAP<NetworkState_Impl, unsigned int>* merged_fixpoint_map = mergeFixpointMaps();

  STATE_MAP<NetworkState_Impl, unsigned int>::const_iterator b = merged_fixpoint_map->begin();
  STATE_MAP<NetworkState_Impl, unsigned int>::const_iterator e = merged_fixpoint_map->end();

  while (b != e) {
    fixpoints[NetworkState((*b).first).getState()] = (*b).second;
    ++b;
  }
  delete merged_fixpoint_map;
}

void MaBEstEngine::display(std::ostream& output_probtraj, std::ostream& output_statdist, std::ostream& output_fp) const
{
  Probe probe;
  merged_cumulator->displayCSV(network, refnode_count, output_probtraj, output_statdist);
  probe.stop();
  elapsed_statdist_runtime = probe.elapsed_msecs();
  user_statdist_runtime = probe.user_msecs();

  unsigned int statdist_traj_count = RunConfig::getInstance()->getStatDistTrajCount();
  if (statdist_traj_count == 0) {
    output_statdist << "Trajectory\tState\tProba\n";
  }

  output_fp << "Fixed Points (" << fixpoints.size() << ")\n";
  if (0 == fixpoints.size()) {
    return;
  }


  //std::map<NetworkState, unsigned int>::const_iterator begin = fixpoints.begin();
  //std::map<NetworkState, unsigned int>::const_iterator end = fixpoints.end();
  STATE_MAP<NetworkState_Impl, unsigned int>::const_iterator begin = fixpoints.begin();
  STATE_MAP<NetworkState_Impl, unsigned int>::const_iterator end = fixpoints.end();
  
  output_fp << "FP\tProba\tState\t";
  network->displayHeader(output_fp);
  for (unsigned int nn = 0; begin != end; ++nn) {
    const NetworkState& network_state = (*begin).first;
    output_fp << "#" << (nn+1) << "\t";
    output_fp << ((double)(*begin).second / sample_count) <<  "\t";
    network_state.displayOneLine(output_fp, network);
    output_fp << '\t';
    network_state.display(output_fp, network);
    ++begin;
  }
}

MaBEstEngine::~MaBEstEngine()
{
  for (std::vector<Cumulator*>::iterator iter = cumulator_v.begin(); iter < cumulator_v.end(); ++iter) {
    delete *iter;
  }

  for (std::vector<STATE_MAP<NetworkState_Impl, unsigned int>*>::iterator iter = fixpoint_map_v.begin(); iter < fixpoint_map_v.end(); ++iter) {
    delete *iter;
  }

  for (std::vector<ArgWrapper*>::iterator iter = arg_wrapper_v.begin(); iter < arg_wrapper_v.end(); ++iter) {
    delete *iter;
  }

  delete merged_cumulator;
  delete [] tid;
}
