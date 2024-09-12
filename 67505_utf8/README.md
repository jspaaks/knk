# 67505_utf8

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
$ ./dist/bin/demo
Program to demonstrate printing code points in the range 0x80-0xFF.
 -- déjà vu
 -- Côte d'Azur
 -- crème brûlée*
 -- crème fraîche*
 -- Fahrvergnügen
 -- tète á tète
Used code page from https://www.charset.org/utf-8 to encode this.
* Required string splitting.
```

