# 58310_fcopy

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
echo "hello" > hello.txt
./dist/bin/fcopy hello.txt hello-again.txt
```

Should copy the contents of `hello.txt` to `hello-again.txt`.

Some error checking happens as well, see below:

```text
$ ./dist/bin/fcopy
Usage: fcopy SRC DST
Copy a file from SRC to DST.
```

```text
$ ./dist/bin/fcopy hello.txt
Usage: fcopy SRC DST
Copy a file from SRC to DST.
```

```text
$ ./dist/bin/fcopy doesntexist.txt hello-again.txt
Could not open source file 'doesntexist.txt'. Aborting.
```

```text
$ ./dist/bin/fcopy hello.txt /hello-again.txt
Could not open destination file '/hello-again.txt'. Aborting.
```

```text
# (disk full)
$ ./dist/bin/fcopy hello.txt hello-again.txt
An error occurred while copying from 'hello.txt' to 'hello-again.txt'. Aborting.
```
