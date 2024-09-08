# 62408_count_char

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
$ ./dist/bin/count --help                                                                                                                         
Usage: count STR CH
    Count the occurrences of character CH in string STR.

$ ./dist/bin/count "Aegon Targaryen" a
Character 'a' occurs 2 times in string 'Aegon Targaryen'.
```

