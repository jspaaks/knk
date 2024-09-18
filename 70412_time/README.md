# 70412_time

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
$ ./dist/bin/yearstart --help
Usage: yearstart YYYY
    Return a datetime for the start of the year YYYY.

$ ./dist/bin/yearstart 1970
12:00a on January 1, 1970 (local time) equals
epoch seconds  18000
ctime()        Thu Jan  1 00:00:00 1970
```

