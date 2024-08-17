# 52501_bitops

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
./dist/bin/program
```

should output something like:

```text
a
 -- i = 8;
 -- j = 9;
 -- i >> 1 + j >> 1: 0
 -- i >> (1 + j) >> 1: 0
b
 -- i = 1;
 -- i & ~i: 0
c
 -- i = 2;
 -- j = 1;
 -- k = 0;
 -- ~i & j ^ k: 1
 -- (~i & j) ^ k: 1
d
 -- i = 7;
 -- j = 8;
 -- k = 9;
 -- i ^ j & k: 15
 -- i ^ (j & k): 15

```
