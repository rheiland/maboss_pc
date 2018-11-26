# maboss_pc

This repo is an edited version of https://maboss.curie.fr/pub/MaBoSS-env-2.0.tgz . The goal is to provide a single code base that will compile and run on Linux, OSX, and Windows/MinGW-w64(with POSIX threading). This is in preparation for incorporating MaBoSS into PhysiCell (hence the "_pc"). Instructions for setting up a proper MinGW-w64 can be found at http://www.mathcancer.org/blog/setting-up-a-64-bit-gcc-environment-on-windows/. HOWEVER, instead of selecting "win32" as your Threads model, you should choose "posix".

Briefly, some of the changes that have been made to accommodate building on MinGW are:

* allow only "StandardRandomGenerator" (a PRNG), not "PhysicalRandomGenerator"; warn/halt if the latter
* replace <sys/time.h> and <sys/times.h> in Probe.h (and related files...)

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

