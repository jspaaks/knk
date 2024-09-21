# 73404_roots_of_unity

https://en.wikipedia.org/wiki/Root_of_unity

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
$ ./dist/bin/roots --help
Usage: roots N
    Program to print the roots 0..N-1 of unity.

$ ./dist/bin/roots 1
Program to print the roots of unity.
k     z
0       1 + 0

$ ./dist/bin/roots 2
Program to print the roots of unity.
k     z
0       1 + 0
1      -1 + 1.22465e-16

$ ./dist/bin/roots 3
Program to print the roots of unity.
k     z
0       1 + 0
1      -0.5 + 0.866025
2      -0.5 - 0.866025

$ ./dist/bin/roots 4
Program to print the roots of unity.
k     z
0       1 + 0
1       6.12323e-17 + 1
2      -1 + 1.22465e-16
3      -1.83697e-16 - 1

$ ./dist/bin/roots 5
Program to print the roots of unity.
k     z
0       1 + 0
1       0.309017 + 0.951057
2      -0.809017 + 0.587785
3      -0.809017 - 0.587785
4       0.309017 - 0.951057

$ ./dist/bin/roots 6
Program to print the roots of unity.
k     z
0       1 + 0
1       0.5 + 0.866025
2      -0.5 + 0.866025
3      -1 + 1.22465e-16
4      -0.5 - 0.866025
5       0.5 - 0.866025
```

