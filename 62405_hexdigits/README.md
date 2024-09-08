# 62405_hexdigits

## Build and install

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```

## Run

```shell
$ ./dist/bin/checkhex --help
Usage: checkhex STR
    Check whether string STR can be interpreted as hexadecimal
    number, and if so, print it as base 10.

$ ./dist/bin/checkhex 0xff
Base 10 equivalent of '0xff' is '255'.

$ ./dist/bin/checkhex 0Xff
Base 10 equivalent of '0Xff' is '255'.

$ ./dist/bin/checkhex ff
Base 10 equivalent of 'ff' is '255'.

$ ./dist/bin/checkhex 0x7fffffffffffffff
Base 10 equivalent of '0x7fffffffffffffff' is '9223372036854775807'.

$ ./dist/bin/checkhex -0x7fffffffffffffff
Base 10 equivalent of '-0x7fffffffffffffff' is '-9223372036854775807'.

$ ./dist/bin/checkhex 0x8000000000000000
Integer overflow.
```
