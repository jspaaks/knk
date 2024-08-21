# 58414b_my_fputs

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
echo -e "1234\n5678" > input.txt
```

Should output something like:

```text
$cat input.txt
1234
5678   # newline was added by echo call
$ ./dist/bin/my_fputs_demo 6 output.txt <input.txt
BUFSIZE 6 requested.
Wrote 6 characters from STDIN to file 'output.txt'.
$ cat output.txt
1234
5      # no newline
```


```text
$ ./dist/bin/my_fputs_demo 1024 output.txt <input.txt
BUFSIZE 1024 requested.
Wrote 10 characters from STDIN to file 'output.txt'.
cat output.txt
1234
5678  # has newline
```
