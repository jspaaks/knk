# 70309_unit_random

## Build and install

```console
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```

## Run

```console
$ ./dist/bin/demo --help
Usage: demo N
   Draw a sequence of N unit random numbers.
   Note that the program uses time in seconds to seed the pseudo
   random number generator, so allow at least one second between
   calls, otherwise you'll get the same sequence of random numbers
   (deterministically, not randomly).

$ ./dist/bin/demo asd
Error parsing 'asd' as a positive integer number, aborting.

$ ./dist/bin/demo -5
Argument N should be a positive integer. Aborting.

$ ./dist/bin/demo 1
Here is 1 unit random number:
0.319356

$ ./dist/bin/demo 5
Here are 5 unit random numbers:
0.899651
0.397617
0.729074
0.549802
0.219053
```

