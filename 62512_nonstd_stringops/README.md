# 62512_nonstd_stringops

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
$ ./dist/bin/stringalong
a) Test mystrdup:
   -- 0x7fff5ea8943a: hello strings
   -- 0x5f74233286b0: hello strings

b) Test mystricmp:
   -- strcmp("abc", "abc") = 0
   -- mystricmp("abc", "abc") = 0

   -- strcmp("abc", "ABC") = 32
   -- mystricmp("abc", "ABC") = 0

   -- strcmp("abc", "ABC") = 32
   -- mystricmp("abc", "ABC") = 0

   -- strcmp("abcd", "ABC") = 32
   -- mystricmp("abcd", "ABC") = 100

   -- strcmp("ABC", "abcd") = -32
   -- mystricmp("ABC", "abcd") = -100

   -- strcmp("abc", "ABCD") = 32
   -- mystricmp("abc", "ABCD") = -100

   -- strcmp("ABCD", "abc") = -32
   -- mystricmp("ABCD", "abc") = 100

c) Test mystrlwr:
   -- before: 'Testing ONE Two *&^ (-98 JKHG'
   -- after : 'testing one two *&^ (-98 jkhg'

d) Test mystrrev:
   -- before: 'flip it!'
   -- after : '!ti pilf'

e) Test mystrset:
   -- before: 'abcde'
   -- after : '*****'

```

