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
