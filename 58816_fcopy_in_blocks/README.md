# 58816_fcopy_in_blocks

## Build and install

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```

# Prep

```
$ echo -ne "sometext\n" > test.in
$ xxd test.in                                                                                                                                                                                                                                                                                                
00000000: 736f 6d65 7465 7874 0a                   sometext.
```

## Run

```shell
$ ./dist/bin/fcopy test.in test.out
$ xxd test.out
00000000: 736f 6d65 7465 7874 0a                   sometext.
```

