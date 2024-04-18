# KNK

Programming exercises for KN King's book _C programming - a modern approach_.

Compile `*.c` files with:

```shell
export BASENAME=<filename without '.c' extension>
gcc -Wall -Wextra -std=c99 ${BASENAME}.c -o ${BASENAME}.bin
```

Then run the binary with:

```shell
./${BASENAME}.bin
```

Makefiles are introduced at 359, for later projects, do

```shell
make
```
The above command should generate an executable file, e.g. `justify` which can then be run as follows:

```shell
./justify
```
