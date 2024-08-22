# 58503_fcat

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
echo hello > ../hello.txt
echo world > ../world.txt
```

## Run

```shell
$ ./dist/bin/fcat ../hello.txt ../world.txt asdasd
Error opening file 'asdasd': No such file or directory.
$ ./dist/bin/fcat hello.txt world.txt
hello
world
```
