#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

int main (void) {
    struct s {
        char a;
        int b[2];
        float c;
        int d;
    };

    fprintf(stdout, "name   type     offset   size\n");
    fprintf(stdout, "a      char     %-6ld   %-4ld\n", offsetof(struct s, a), sizeof(char));
    fprintf(stdout, "b      int[2]   %-6ld   %-4ld\n", offsetof(struct s, b), sizeof(int[2]));
    fprintf(stdout, "c      float    %-6ld   %-4ld\n", offsetof(struct s, c), sizeof(float));
    fprintf(stdout, "d      int      %-6ld   %-4ld\n", offsetof(struct s, d), sizeof(int));
    fprintf(stdout, "total size in bytes is: %ld\n", sizeof(struct s));
    return EXIT_SUCCESS;
}   
