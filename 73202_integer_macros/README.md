# 73202_integer_macros

## Build and install

```console
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```

## Run

After running 

```console
gcc- E ../src/main.c
```

the output should contain something like:

```console
    int32_t i32 = 2147483647;
    uint32_t u32 = 4294967295U;
    int64_t i64 = 9223372036854775807LL;
    uint64_t u64 = 18446744073709551615ULL;
```

(near the bottom).

```shell
$ ./dist/bin/demo --help
Usage: demo
   Demonstrate the pain C inflicts because int is not fixed size across systems.

$ ./dist/bin/demo
int32_t : 2147483647
uint32_t: 4294967295
int64_t : 9223372036854775807
uint64_t: 18446744073709551615
```

