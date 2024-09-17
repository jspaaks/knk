# 70308_random_values

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
Usage: demo
   Randomly assign one of 7, 11, 15, 19 to a variable n.
   Note that the program uses time in seconds to seed the pseudo
   random number generator, so allow at least one second between
   calls, otherwise you'll get the same number (deterministically,
   not randomly).

$ ./dist/bin/demo 
Randomly assigned n = 19.

$ ./dist/bin/demo                                                                                                                                 
Randomly assigned n = 11.

$ ./dist/bin/demo                                                                                                                                 
Randomly assigned n = 15.

$ ./dist/bin/demo                                                                                                                                 
Randomly assigned n = 7.

$ ./dist/bin/demo                                                                                                                                 
Randomly assigned n = 11.

$ ./dist/bin/demo                                                                                                                                 
Randomly assigned n = 15.

$ ./dist/bin/demo                                                                                                                                 
Randomly assigned n = 11.

$ ./dist/bin/demo                                                                                                                                 
Randomly assigned n = 15.

```

