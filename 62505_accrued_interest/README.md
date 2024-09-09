# 62505_accrued_interest

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
$ ./dist/bin/accrue --help
 -- Usage: accrue
 --    Program to calculate accrued interest.
$ ./dist/bin/accrue
Program prompts the user for some inputs, then calculates accrued interest.
 -- How much was the original amount? 1000
 -- What is the yearly interest rate in percent? 6
 -- How many years? 10
 -- An original amount of $1000.00 plus 6.00% interest for 10 years equals $1822.12.
```

