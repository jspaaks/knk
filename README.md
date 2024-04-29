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
The above command should generate an executable file, e.g. `justify`, which can then be run as follows:

```shell
./justify
```

Clean up the tree with:

```shell
make clean
```

## Other

- https://cdecl.org/ for decoding declarations


`valgrind` can help detect memory errors:

```shell
$ valgrind ./program
$ valgrind --leak-check=full --show-leak-kinds=all ./program
```

See https://valgrind.org/ for more information.

`clang-format` formats *.c files (as well as other formats), is customizable, and can inherit
from existing published style guide, e.g. Google, LLVM, etc. See
https://clang.llvm.org/docs/ClangFormatStyleOptions.html. 

```shell
# print warnings, don't change files
clang-format -Werror --dry-run main.c

# change file in-place
clang-format -i main.c
```
