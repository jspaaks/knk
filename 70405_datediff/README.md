# 70405_datediff

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
$ ./dist/bin/datediff --help
Usage: datediff
    Prompts the user to enter two dates and returns the
    number of dates between them.

$ ./dist/bin/datediff
Please enter the first date (DD-MM-YYYY): 5-12-2021
Please enter the second date (DD-MM-YYYY): 4-1-2022
05-12-2021 and 04-01-2022 have 30 days separation.
```

