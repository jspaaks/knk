# 70307_strtol

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
Usage: demo STR
    Demonstrate parsing of a string STR that contains an integer number.

$ ./dist/bin/demo 456.4
Parsed as base-10 integer 456 with parsing errors.

$ ./dist/bin/demo 456
Parsed as base-10 integer 456 without parsing errors.
```

