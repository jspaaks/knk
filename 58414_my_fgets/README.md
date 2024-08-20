# 58414_my_fgets

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
echo -e "0123456789\nmore text\nthat should be ignored" > input.txt
```

Should output something like:

```text
$ ./dist/bin/my_fgets_demo 0 <input.txt                                                                                                                                                                                                                                      
Can't use zero-capacity buffer. Aborting.
```

```text
$ ./dist/bin/my_fgets_demo 1 <input.txt                                                                                                                                                                                                                                                                     
Need space to terminate buffered string with \0. Aborting.
```

```text
$ ./dist/bin/my_fgets_demo 2 <input.txt                                                                                                                                                                                                                                                                     
Bufsize 2 requested.
0           # no newline
```

```text
$ ./dist/bin/my_fgets_demo 11 <input.txt
Bufsize 11 requested.
0123456789  # no newline
```

```text
$ ./dist/bin/my_fgets_demo 12 <input.txt
Bufsize 12 requested.
0123456789
             # buffer size was large enough to include newline and \0
```
