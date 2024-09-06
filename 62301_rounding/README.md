# 62301_rounding

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
./dist/bin/round
```

Should output something like:

```text
 0.97531 rounded to nearest 0 digits =  1.000
 0.97531 rounded to nearest 1 digits =  1.000
 0.97531 rounded to nearest 2 digits =  0.980
 1.23456 rounded to nearest 0 digits =  1.000
 1.23456 rounded to nearest 1 digits =  1.200
 1.23456 rounded to nearest 2 digits =  1.230
-0.97531 rounded to nearest 0 digits = -1.000
-0.97531 rounded to nearest 1 digits = -1.000
-0.97531 rounded to nearest 2 digits = -0.980
-1.23456 rounded to nearest 0 digits = -1.000
-1.23456 rounded to nearest 1 digits = -1.200
-1.23456 rounded to nearest 2 digits = -1.230
```

