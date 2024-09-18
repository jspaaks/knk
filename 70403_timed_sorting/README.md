# 70403_timed_sorting

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
   Demonstrate measuring the duration of sort operations on a
   reverse-sorted array of integers of various lengths.

$ ./dist/bin/demo
Sorting 1000 integers took 0.000064 seconds.
Sorting 10000 integers took 0.000699 seconds.
Sorting 100000 integers took 0.003844 seconds.
```

