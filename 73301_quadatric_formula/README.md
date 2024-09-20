# 73301_quadratic_formula

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
$ ./dist/bin/quadratic --help
Usage: quadratic
    Program that prompts the user for coefficients of a quadratic
    function ax^2 + bx + c = 0, then determines its root(s).

$ ./dist/bin/quadratic
Program for finding the roots of a quadratic function ax^2 + bx + c = 0
 -- Enter a value for coefficient a: 2
 -- Enter a value for coefficient b: 4
 -- Enter a value for coefficient c: 2
 -- a = 2.000000, b = 4.000000, c = 2.000000
 -- Only one root exists: -1.000000

$ ./dist/bin/quadratic
Program for finding the roots of a quadratic function ax^2 + bx + c = 0
 -- Enter a value for coefficient a: 2
 -- Enter a value for coefficient b: 4
 -- Enter a value for coefficient c: 1
 -- a = 2.000000, b = 4.000000, c = 1.000000
 -- Two roots exist: -1.707107 and -0.292893

$ ./dist/bin/quadratic
Program for finding the roots of a quadratic function ax^2 + bx + c = 0
 -- Enter a value for coefficient a: 2
 -- Enter a value for coefficient b: 4
 -- Enter a value for coefficient c: 3
 -- a = 2.000000, b = 4.000000, c = 3.000000
 -- Two roots exist: -1 - 0.707107i and -1 + 0.707107i
```

