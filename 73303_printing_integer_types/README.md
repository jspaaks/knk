# 73303_printing_integer_types

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
Usage: demo
    Demonstrate printing macros for integers of different width.

$ ./dist/bin/demo
a)78,78;
b)        2345,        2345;
c)710   ,710   ;
d)0xdef,0xdef;
```

