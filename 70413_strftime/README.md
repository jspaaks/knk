# 70413_strftime

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
    Print time_t t = 1234567890 in various formats using strftime.

$ ./dist/bin/demo
 -- a) 2009-044
 -- b) 2009-W07-5
 -- c) 2009-02-13T18:31:30
```

