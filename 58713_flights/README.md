# 58713_flights

## Build and install

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```

## Prep

```text
cat ../flights.dat
8:00 10:16
9:43 11:52
11:19 13:31
12:47 15:00
14:00 16:08
15:45 17:55
19:00 21:20
21:45 23:58
```

## Run

```text
$ ./dist/bin/whichflight ../flights.dat
Enter a 24-hour time: 13:15
 -- Requested minute of day: 795
 -- Read data of 8 flights.
 -- Closest departure time is 12:47 PM, arriving at 3:00 PM.
```

