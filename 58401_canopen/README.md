# 58401_canopen

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
$ ./dist/bin/canopen ./canopen ./doesntexist /usr/include/assert.h /sys/module/random/uevent
```

Should output something like:

```text
                                | can be opened | cannot be opened | reason
./canopen ..................... | ..... ✓ ..... | ................ |
./doesntexist ................. | ............. | ...... ✓ ....... | No such file or directory
/usr/include/assert.h ......... | ..... ✓ ..... | ................ |
/sys/module/random/uevent ..... | ............. | ...... ✓ ....... | Permission denied
```
