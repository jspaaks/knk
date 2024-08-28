# 58711_date_parsing

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
$ ./dist/bin/dateparse
Enter a date: 9-13-2010
September 13, 2010
$ ./dist/bin/dateparse                                                                                                                            
Enter a date: 9/13/2010
September 13, 2010
$ ./dist/bin/dateparse extra_arg
Usage: dateparse
    Read datestring from STDIN and display it as %B %d, %Y.
    Supported input formats are:
      %m-%d-%Y
      %m/%d/%Y
```

