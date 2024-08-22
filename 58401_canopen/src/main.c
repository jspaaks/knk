#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[]) {
    if (argc == 1) {
        fprintf(stderr, "Usage: %s FILENAME1 [FILENAME2] [...]\n", argv[0]);
        fprintf(stderr, "Test whether the files indicated by FILENAME1,\nFILENAME2, ... can be opened or not.\n");
        exit(EXIT_FAILURE);
    }

    if (argc == 2 && strncmp(argv[1], "er", 2) == 0) {
        fprintf(stdout, "canopen er? I barely know her!\n");
        exit(EXIT_SUCCESS);
    }

    unsigned int longest = 0;
    unsigned int nnames = argc - 1;
    for (unsigned int iname = 0; iname < nnames; ++iname) {
        unsigned int ell = strlen(argv[iname + 1]);
        longest = ell > longest ? ell : longest;
    }
    longest += 5;

    char * dots = malloc(longest * 1 + 5 + 1);
    char * spaces = malloc(longest * 1 + 5 + 1);
    for (size_t i = 0; i < longest; ++i) {
        dots[i] = '.';
        spaces[i] = ' ';
    }

    bool complete_success = true;
    fprintf(stdout, " %.*s | can be opened | cannot be opened | reason\n", (int) longest, spaces);
    FILE * fp;
    for (unsigned int iname = 0; iname < nnames; ++iname) {
        char * filename = argv[iname + 1];
        fp = fopen(filename, "r");
        if (fp == NULL) {
            fprintf(stdout, "%s %.*s | ............. | ...... \u2713 ....... | %s\n", filename,
                    (int) (longest - strlen(filename)), dots, strerror(errno));
            errno = 0;
            complete_success = false;
            continue;
        }
        fprintf(stdout, "%s %.*s | ..... \u2713 ..... | ................ |\n", filename,
                (int) (longest - strlen(filename)), dots);
        int status = fclose(fp);
        if (status != 0) {
            fprintf(stderr, "Error closing file '%s': %s.\n", filename, strerror(errno));
        }
    }
    free(dots);
    free(spaces);
    return complete_success ? EXIT_SUCCESS : EXIT_FAILURE;
}
