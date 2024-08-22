# 58504_count

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
cat ../input.txt
a bb ccc
d ee
f
```

## Run

```shell
./dist/bin/count -l ../input.txt
3
./dist/bin/count --lines ../input.txt
3
./dist/bin/count -w ../input.txt
6
./dist/bin/count --words ../input.txt
6
./dist/bin/count -c ../input.txt
16
./dist/bin/count --characters ../input.txt
16
```
