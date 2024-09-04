# 58818_reading_ints

## Build and install

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```

## Prep

```shell
$ cat ../input.txt

  
24 -1235   34 
2 46 5634 5 -6 3 45
-6 

7456 78
5
 95 6 8 -9 

8 3     566 -4
 
3
 4 -1 2  3
   -4 6 3 
-585 -6 89
  57 -8 9 3
5 6 
-745


```

## Run

```shell
$ ./dist/bin/readints ../input.txt
```

Should output something like:

```text
nints  :    40
minimum: -1235
maximum:  7456
median :     4.50
```

