# 62404_c_identifiers

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
./dist/bin/identifiers
```

Should output something like:

```text
string             is valid   is not valid
----------------   --------   ------------
napples                x
number_of_apples       x
#apples                            x
numberOfApples         x
NumberOfApples         x
_state                 x
number-of-apples                   x
n'                                 x
0apples                            x
apples!                            x
apples[4]                          x
```

