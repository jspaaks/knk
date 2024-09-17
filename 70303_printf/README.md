# 70303_printf

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
    Demo homegrown printf.

$ ./dist/bin/demo
single digit int 5
two-digit int 56
multiple ints 444, 55, 6
single string 'hello, world'.
two strings 'hello', 'world'.
all together now 123, 'hello', 45678, 'world', 9.
```
