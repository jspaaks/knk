Programming exercises for KN King's book _C programming - a modern approach_.

Compile `*.c` files with:

```shell
export BASENAME=<filename without '.c' extension>
gcc -Wall -Wextra ${BASENAME}.c -o ${BASENAME}.bin
```

Then run the binary with: 

```shell
./${BASENAME}.bin
```
