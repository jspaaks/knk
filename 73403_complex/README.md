# 73403_complex

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
$ ./dist/bin/convert --help
Usage: convert
    Program to convert a complex number from Cartesian to polar coordinates.

$ ./dist/bin/convert
Program to convert a complex number from Cartesian to polar coordinates.
 -- Enter the magnitude of the complex number: 1
 -- Enter the argument of the complex number in degrees: 60
0.866025 + 0.5i

$ ./dist/bin/convert
Program to convert a complex number from Cartesian to polar coordinates.
 -- Enter the magnitude of the complex number: 1
 -- Enter the argument of the complex number in degrees: 120
0.866025 - 0.5i

$ ./dist/bin/convert
Program to convert a complex number from Cartesian to polar coordinates.
 -- Enter the magnitude of the complex number: 1
 -- Enter the argument of the complex number in degrees: 240
-0.866025 - 0.5i

$ ./dist/bin/convert
Program to convert a complex number from Cartesian to polar coordinates.
 -- Enter the magnitude of the complex number: 1
 -- Enter the argument of the complex number in degrees: 300
-0.866025 + 0.5i
```

