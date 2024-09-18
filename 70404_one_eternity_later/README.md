# 70404_one_eternity_later

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
$ ./dist/bin/dayslater --help
Usage: dayslater
   Prompts the user for a date (MM-DD-YYYY) and a number of days N,
   then returns the date that is N days after the reference date.

$ ./dist/bin/dayslater
Please enter the reference date (MM-DD-YYYY): 7-17-2019
Please enter the number of days: 15
'08-01-2019' is 15 days after the reference date '07-17-2019'.
```

