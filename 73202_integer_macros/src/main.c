#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

/* These macros assume:
   int == int32
   long int == int32
   long long int == int64 
   unsigned int == uint32
   unsigned long int == uint32
   unsigned long long int == uint64 
*/

#define MY_INT32_C(n) n
#define MY_UINT32_C(n) n ## U
#define MY_INT64_C(n) n ## LL
#define MY_UINT64_C(n) n ## ULL

void show_usage (FILE *);

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 1) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    int32_t i32 = MY_INT32_C(2147483647);
    uint32_t u32 = MY_UINT32_C(4294967295);
    int64_t i64 = MY_INT64_C(9223372036854775807);
    uint64_t u64 = MY_UINT64_C(18446744073709551615);

    fprintf(stdout, "int32_t : %" PRId32 "\n", i32);
    fprintf(stdout, "uint32_t: %" PRIu32 "\n", u32);
    fprintf(stdout, "int64_t : %" PRId64 "\n", i64);
    fprintf(stdout, "uint64_t: %" PRIu64 "\n", u64);

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "demo";
    fprintf(stream,
            "Usage: %s\n"
            "   Demonstrate the pain C inflicts because int is not fixed size across systems.\n",
            exename);
}

