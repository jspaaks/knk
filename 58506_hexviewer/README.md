# 58506_hexviewer

## Build and install

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```

# Prep

```shell
cat ../pun.c
#include <stdio.h>

int main (void) {
    printf("To C, or not to C: that is the question.\n");
    return 0;
}
```

## Run

```shell
./dist/bin/hexview ../pun.c
```

Should output:

```text
$ ./dist/bin/hexview ../pun.c
           0  1  2  3  4  5  6  7  8  9
      0x  23 69 6e 63 6c 75 64 65 20 3c  #include <
      1x  73 74 64 69 6f 2e 68 3e 0a 0a  stdio.h>..
      2x  69 6e 74 20 6d 61 69 6e 20 28  int main (
      3x  76 6f 69 64 29 20 7b 0a 20 20  void) {.  
      4x  20 20 70 72 69 6e 74 66 28 22    printf("
      5x  54 6f 20 43 2c 20 6f 72 20 6e  To C, or n
      6x  6f 74 20 74 6f 20 43 3a 20 74  ot to C: t
      7x  68 61 74 20 69 73 20 74 68 65  hat is the
      8x  20 71 75 65 73 74 69 6f 6e 2e   question.
      9x  5c 6e 22 29 3b 0a 20 20 20 20  \n");.    
     10x  72 65 74 75 72 6e 20 30 3b 0a  return 0;.
     11x  7d 0a                          }.
```

For comparison, `xxd` shows:

```text
$ xxd -c 10 ../pun.c
00000000: 2369 6e63 6c75 6465 203c  #include <
0000000a: 7374 6469 6f2e 683e 0a0a  stdio.h>..
00000014: 696e 7420 6d61 696e 2028  int main (
0000001e: 766f 6964 2920 7b0a 2020  void) {.  
00000028: 2020 7072 696e 7466 2822    printf("
00000032: 546f 2043 2c20 6f72 206e  To C, or n
0000003c: 6f74 2074 6f20 433a 2074  ot to C: t
00000046: 6861 7420 6973 2074 6865  hat is the
00000050: 2071 7565 7374 696f 6e2e   question.
0000005a: 5c6e 2229 3b0a 2020 2020  \n");.    
00000064: 7265 7475 726e 2030 3b0a  return 0;.
0000006e: 7d0a                      }.
```
