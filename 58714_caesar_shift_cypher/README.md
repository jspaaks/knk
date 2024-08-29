# 58714_caesar_shift_cypher

## Build and install

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```

# Prep

```text
$ cat ../input.txt
Go ahead, make my day.

```


## Run

```shell
./dist/bin/caesar
```

Should output something like:

```text
$ ./dist/bin/caesar                                                                                                                               
 -- Enter the name of a file to be encrypted: ../input.txt
 -- Requested encrypting contents of '../input.txt'.
 -- Enter shift amount (1-25): 3
 -- Opened file '../input.txt.enc' for writing...
 -- Encrypting...
 -- Done.
```

```text
$ cat ../input.txt.enc                                                                                                                           
Jr dkhdg, pdnh pb gdb.

```

