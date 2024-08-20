# 58413_line_length

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
echo -e "abc\ndefg\n\n" > test.txt
./dist/bin/line-length test.txt 1
```

Should output:

```text
4
```

