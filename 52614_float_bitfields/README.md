# 52614_float_bitfields

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
./dist/bin/program
```

should output something like

```text
Printing type union as struct:
 -- sign: 1
 -- exponent: 128
 -- fraction: 0
Printing that same type union as float:
 -- float: -2.00
```
