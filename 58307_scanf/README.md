# 58307_scanf

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
./dist/bin/program < ../a.txt
./dist/bin/program < ../b.txt
./dist/bin/program < ../c.txt
./dist/bin/program < ../d.txt
```

Should output something like:

```text
i = 10, x = 20.000000, j = 30; read 3 elements.
```

```text
i = 1, x = 0.000000, j = 2; read 3 elements.
```

```text
i = 0, x = 0.100000, j = 0; read 3 elements.
```

```text
i = -1114424592, x = 0.000000, j = 29964; read 0 elements.
```

