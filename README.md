# KNK

Programming exercises for KN King's book _C programming - a modern approach_.

## Pre 359

Compile `*.c` files with:

```shell
export BASENAME=<filename without '.c' extension>
gcc -Wall -Wextra -std=c99 ${BASENAME}.c -o ${BASENAME}.bin
```

Then run the binary with:

```shell
./${BASENAME}.bin
```

## Post 359

Makefiles are introduced at 359. Compile subsequent projects with:

```shell
make
```
The above command should generate an executable file, e.g. `program`, which can then be run as follows:

```shell
./program
```

Clean up the tree with:

```shell
make clean
```

## Formatting with `clang-format`

`clang-format` formats *.c files (as well as other formats), is customizable, and can inherit
from existing published style guide, e.g. Google, LLVM, etc. See
https://clang.llvm.org/docs/ClangFormatStyleOptions.html. 

```shell
# print warnings, don't change files
clang-format -Werror --dry-run main.c

# print main.c to stdout including changes,
# but don't change main.c itself
clang-format main.c

# change file in-place
clang-format -i main.c
```

## Debugging with Valgrind: memcheck

`valgrind` can help detect various kinds of errors. By default it runs `memcheck`, which detects memory errors:

```shell
$ valgrind ./program
$ valgrind tool=memcheck ./program
$ valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./program
```

To have Valgrind output the relevant line numbers, recompile the binary with `-g` flag ("include debugging information")
and `-O0` ("disable optimization"). Note that this requires recompiling the objects as well.

See https://valgrind.org/ for more information.

## Debugging with Valgrind: cachegrind

\# TODO

## Debugging with Valgrind: callgrind

\# TODO

## Other

- https://cdecl.org/ for decoding declarations

---

Have `gcc` generate Assembler code

```shell
gcc -c -S main.c   # generates main.s
```
