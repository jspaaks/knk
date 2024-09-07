# 62402_horners_rule

## Build and install

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```

## Prep

```shell
echo -ne "2 -6 2 -1\n" > ../coefs.txt
```

## Run

```shell
./dist/bin/polynomial ../coefs.txt 3.0
```

Should output something like:

```text
2.000000x^3 + -6.000000x^2 + 2.000000x + -1.000000
 ✦ brute force        : 5.000000
 ✦ brute force (fma)  : 5.000000
 ✦ horner's rule (fma): 5.000000
```

## Recap of Horner's rule

E.g. for a 3rd order polynomial,

```text
  a3 * x^3 + a2 * x^2 + a1 * x^1 + a0 * x^0
= a3 * x^3 + a2 * x^2 + a1 * x^1 + a0
= a3 * x^3 + a2 * x^2 + a1 * x + a0
```

Raising to the power is expensive, so factor out `x` from terms like `a * x^{n}` to `x * (a * x^{n-1})`, repeat pattern until n-1 becomes 0:

```text
  a3 * x^3 + a2 * x^2 + a1 * x + a0
= (a3 * x^2 + a2 * x + a1) * x + a0
= ((a3 * x + a2) * x + a1) * x + a0
```

Let's see for an example of 4 coefficients a3-a0:

```text

a3 =  2
a2 = -6
a1 =  2
a0 = -1

= ((a3 * x + a2) * x + a1) * x + a0
= ((2 * 3 - 6) * 3 + 2) * 3 - 1
= (0 * 3 + 2) * 3 - 1
= 2 * 3 - 1
= 5
```
