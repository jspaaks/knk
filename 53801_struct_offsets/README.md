# 53801_struct_offsets

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
./dist/bin/program
```

Should output something like:

```text
name   type     offset   size
a      char     0        1   
b      int[2]   4        8   
c      float    12       4   
d      int      16       4   
total size in bytes is: 20
```

