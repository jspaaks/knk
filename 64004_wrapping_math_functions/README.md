# 64004_wrapping_math_functions

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
Usage: demo X
    Calculate the value of sqrt(X).
$ ./dist/bin/demo 16
Sqrt of 16.000000 is 4.000000.
$ ./dist/bin/demo -16
Error in call to sqrt: Numerical argument out of domain
```

