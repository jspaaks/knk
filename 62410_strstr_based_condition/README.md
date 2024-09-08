# 62410_strstr_based_condition

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
$ ./dist/bin/demo --help
Usage: demo STR
    Compare two methods of determining whether string STR is one
    of 'foo', 'bar', 'baz' or not.

$ ./dist/bin/demo -h
Usage: demo STR
    Compare two methods of determining whether string STR is one
    of 'foo', 'bar', 'baz' or not.

$ ./dist/bin/demo foo
According to method 1, 'foo' is one of 'foo', 'bar', 'baz'.
According to method 2, 'foo' is one of 'foo', 'bar', 'baz'.
Methods are equivalent.

$ ./dist/bin/demo bar
According to method 1, 'bar' is one of 'foo', 'bar', 'baz'.
According to method 2, 'bar' is one of 'foo', 'bar', 'baz'.
Methods are equivalent.

$ ./dist/bin/demo baz
According to method 1, 'baz' is one of 'foo', 'bar', 'baz'.
According to method 2, 'baz' is one of 'foo', 'bar', 'baz'.
Methods are equivalent.

$ ./dist/bin/demo "beep"
According to method 1, 'beep' is not one of 'foo', 'bar', 'baz'.
According to method 2, 'beep' is not one of 'foo', 'bar', 'baz'.
Methods are equivalent.

$ ./dist/bin/demo "foo bar"
According to method 1, 'foo bar' is not one of 'foo', 'bar', 'baz'.
According to method 2, 'foo bar' is one of 'foo', 'bar', 'baz'.
Methods are not equivalent.

$ ./dist/bin/demo foo bar
Usage: demo STR
    Compare two methods of determining whether string STR is one
    of 'foo', 'bar', baz' or not.
```
