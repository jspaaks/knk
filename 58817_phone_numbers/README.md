# 58817_phone_numbers

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
404.817.6900
(215) 686-1776
312-746-6000
877 275 5273
6173434200

```

## Run

```shell
./dist/bin/harmonize ../input.txt
```

Should output something like:

```text
(404) 817-6900
(215) 686-1776
(312) 746-6000
(877) 275-5273
(617) 343-4200
```
