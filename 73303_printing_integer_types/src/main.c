#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_usage (FILE *);
void a (void);

void a (void) {
    printf("a)");
    {
        int i = 78;
        printf("%d,", i);
    }
    {
        int8_t i = 78;
        printf("%" PRId8 ";\n", i);
    }
}

void b (void) {
    printf("b)");
    {
        int i = 2345;
        printf("%12.4d,", i);
    }
    {
        int32_t i = 2345;
        printf("%12.4" PRId32 ";\n", i);
    }
}

void c (void) {
    printf("c)");
    {
        unsigned int i = 456;
        printf("%-6o,", i);
    }
    {
        uint16_t i = 456;
        printf("%-6" PRIo16 ";\n", i);
    }
}

void d (void) {
    printf("d)");
    {
        unsigned int i = 3567;
        printf("%#x,", i);
    }
    {
        uint64_t i = 3567;
        printf("%#" PRIx64 ";\n", i);
    }
}

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 1) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    a();
    b();
    c();
    d();

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "demo";
    fprintf(stream, "Usage: %s\n    Demonstrate printing macros for integers of different width.\n", exename);
}
