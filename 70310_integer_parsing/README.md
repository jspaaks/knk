# 70310_integer_parsing

## Build and install

```console
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```

## Run

```console
$ ./dist/bin/demo --help
Usage: demo STR
    Parse user-supplied string into integer number using various methods.

$ ./dist/bin/demo 12
INT_MAX: 2147483647
LONG_MAX: 9223372036854775807
LLONG_MAX: 9223372036854775807
"12" as parsed by atoi yields 12.
"12" as parsed by strtol yields 12 without any parsing errors.
"12" as parsed by atol yields 12.
"12" as parsed by strtol yields 12 without any parsing errors.
"12" as parsed by atoll yields 12.
"12" as parsed by strtoll yields 12 without any parsing errors.

$ ./dist/bin/demo 12.3
INT_MAX: 2147483647
LONG_MAX: 9223372036854775807
LLONG_MAX: 9223372036854775807
"12.3" as parsed by atoi yields 12.
"12.3" as parsed by strtol yields 12 with parsing errors.
"12.3" as parsed by atol yields 12.
"12.3" as parsed by strtol yields 12 with parsing errors.
"12.3" as parsed by atoll yields 12.
"12.3" as parsed by strtoll yields 12 with parsing errors.

$ ./dist/bin/demo 2147483647
INT_MAX: 2147483647
LONG_MAX: 9223372036854775807
LLONG_MAX: 9223372036854775807
"2147483647" as parsed by atoi yields 2147483647.
"2147483647" as parsed by strtol yields 2147483647 without any parsing errors.
"2147483647" as parsed by atol yields 2147483647.
"2147483647" as parsed by strtol yields 2147483647 without any parsing errors.
"2147483647" as parsed by atoll yields 2147483647.
"2147483647" as parsed by strtoll yields 2147483647 without any parsing errors.

$ ./dist/bin/demo 2147483648
INT_MAX: 2147483647
LONG_MAX: 9223372036854775807
LLONG_MAX: 9223372036854775807
"2147483648" as parsed by atoi yields -2147483648.
"2147483648" as parsed by strtol yields 2147483648 without any parsing errors.
"2147483648" as parsed by atol yields 2147483648.
"2147483648" as parsed by strtol yields 2147483648 without any parsing errors.
"2147483648" as parsed by atoll yields 2147483648.
"2147483648" as parsed by strtoll yields 2147483648 without any parsing errors.

$ ./dist/bin/demo 9223372036854775807
INT_MAX: 2147483647
LONG_MAX: 9223372036854775807
LLONG_MAX: 9223372036854775807
"9223372036854775807" as parsed by atoi yields -1.
"9223372036854775807" as parsed by strtol yields 9223372036854775807 without any parsing errors.
"9223372036854775807" as parsed by atol yields 9223372036854775807.
"9223372036854775807" as parsed by strtol yields 9223372036854775807 without any parsing errors.
"9223372036854775807" as parsed by atoll yields 9223372036854775807.
"9223372036854775807" as parsed by strtoll yields 9223372036854775807 without any parsing errors.

$ ./dist/bin/demo 9223372036854775808
INT_MAX: 2147483647
LONG_MAX: 9223372036854775807
LLONG_MAX: 9223372036854775807
"9223372036854775808" as parsed by atoi yields -1.
"9223372036854775808" as parsed by strtol yields 9223372036854775807 with parsing errors.
"9223372036854775808" as parsed by atol yields 9223372036854775807.
"9223372036854775808" as parsed by strtol yields 9223372036854775807 with parsing errors.
"9223372036854775808" as parsed by atoll yields 9223372036854775807.
"9223372036854775808" as parsed by strtoll yields 9223372036854775807 with parsing errors.
```

