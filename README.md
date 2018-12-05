# maboss_pc

This repo is an edited version of https://maboss.curie.fr/pub/MaBoSS-env-2.0.tgz . The goal is to provide a single code base that will compile and run on Linux, OSX, and Windows/MinGW-w64(with POSIX threading). This is in preparation for incorporating MaBoSS into PhysiCell (hence the "_pc"). Instructions for setting up a proper MinGW-w64 can be found at http://www.mathcancer.org/blog/setting-up-a-64-bit-gcc-environment-on-windows/. HOWEVER, instead of selecting "win32" as your Threads model, you should choose "posix". And if you are building on OSX, you will eventually (for PhysiCell) need to install the OpenMP-enabled gcc using brew (rf. the PhysiCell Quickstart guide).

Briefly, some of the changes that have been made to accommodate building on MinGW are:

* allow only "StandardRandomGenerator" (a PRNG), not "PhysicalRandomGenerator"; warn/halt if the latter
* replace <sys/time.h> and <sys/times.h> in Probe.h (and related files...)
* in engine\src\maboss-config.h, comment out #define HAS_RAND48

Try building the code using (we will show code for Windows; make appropriate changes for *nix):
```
C:\Users\Owner\git\maboss_pc\engine\src> make
```

If it builds OK, try running an example model:
```
C:\Users\Owner\git\maboss_pc\examples\ToyModel>..\..\engine\src\MaBoSS.exe  -c Four_cycle_FEscape.cfg -o Four_cycle_FEscape Four_cycle.bnd

*** Cannot use PhysicalRandomGenerator() on Windows. Use StandardRandomGenerator() instead. ***
      In your .cfg file, you need to set:  use_physrandgen = FALSE;


So we edit the .cfg for this model to tell it NOT to use the PhysicalRandomGenerator:
C:\Users\Owner\git\maboss_pc\examples\ToyModel>gvim Four_cycle_FEscape.cfg
--> 
use_physrandgen = FALSE;
//use_physrandgen = TRUE;

then re-run:
C:\Users\Owner\git\maboss_pc\examples\ToyModel>..\..\engine\src\MaBoSS.exe  -c Four_cycle_FEscape.cfg -o Four_cycle_FEscape Four_cycle.bnd

But get the following assertion error:
Program: C:\Users\Owner\git\maboss_pc\engine\src\MaBoSS.exe
File: MaBEstEngine.cc, Line 103

Expression: node_idx != INVALID_NODE_INDEX
```
Note that the above indicates there's still a problem running on MinGW.

However, when this model runs successfully, it should generate three .csv files and a .txt file:<br>
Four_cycle_FEscape_fp.csv, Four_cycle_FEscape_probtraj.csv, Four_cycle_FEscape_statdist.csv, Four_cycle_FEscape_run.txt

Note different uses of the PhysicalRandomGenerator:
```
~/dev/MaBoSS_original/MaBoSS-env-2.0/examples$ grep use_phys *.cfg
cellcycle_runcfg.cfg:use_physrandgen = TRUE;
p53_Mdm2_runcfg.cfg:use_physrandgen = FALSE;
 
~/dev/MaBoSS_original/MaBoSS-env-2.0/examples$ grep use_phys */*.cfg | grep true
Cell_cycle/cellcycle_runcfg.cfg:use_physrandgen = TRUE;
Exact_matlab_test_ex2/example2_matlab_config.cfg:use_physrandgen = TRUE;
ToyModel/Four_cycle_FEscape.cfg:use_physrandgen = TRUE;
```

Q: How do we visualize the output? Rf. 
* https://maboss.curie.fr/pub/Description_TrajectoryFig.pdf
* https://maboss.curie.fr/pub/README_TrajectoryFig.txt
