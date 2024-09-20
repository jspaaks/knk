# 73402_complex

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
    Program to convert a complex number from Cartesian coordinates to polar.

$ ./dist/bin/convert
Program to convert a complex number from Cartesian coordinates to polar.
 -- Enter the real part of the complex number: 0.866
 -- Enter the imaginary part of the complex number: 0.5
Complex number is:
0.866 + 0.5i (Cartesian).
(0.999978, 59.9993°) (polar).

$ ./dist/bin/convert
Program to convert a complex number from Cartesian coordinates to polar.
 -- Enter the real part of the complex number: 0.866
 -- Enter the imaginary part of the complex number: -0.5
Complex number is:
0.866 - 0.5i (Cartesian).
(0.999978, 120.001°) (polar).

$ ./dist/bin/convert
Program to convert a complex number from Cartesian coordinates to polar.
 -- Enter the real part of the complex number: -0.866
 -- Enter the imaginary part of the complex number: -0.5
Complex number is:
-0.866 - 0.5i (Cartesian).
(0.999978, 239.999°) (polar).

$ ./dist/bin/convert
Program to convert a complex number from Cartesian coordinates to polar.
 -- Enter the real part of the complex number: -0.866
 -- Enter the imaginary part of the complex number: 0.5
Complex number is:
-0.866 + 0.5i (Cartesian).
(0.999978, 300.001°) (polar).
```

