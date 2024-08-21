#include <stdio.h>
#include <stdlib.h>

char * my_fgets (const size_t ncharsmax, char (*buf)[ncharsmax], FILE * fp) {
    char * p = (char *) buf;
    for (size_t i = 0; i < ncharsmax - 1; ++i) {
        int ch = fgetc(fp);
        if (ch == EOF) break;
        *p = ch;
        p++;
        if (ch == '\n') break;
    }
    // Add terminating NULL byte
    *p = '\0';
    return (char *) buf;
}

int main (int argc, char * argv[]) {

    if (argc != 2) {
        fprintf(stdout, "Usage: %s BUFSIZE\n", argv[0]);
        fprintf(stdout, "Read string from stdin into a buffer of size BUFSIZE bytes.\n");
        exit(EXIT_FAILURE);
    }

    int bufsize;
    sscanf(argv[1], " %d", &bufsize);
    if (bufsize == 0) {
        fprintf(stderr, "Can't use zero-capacity buffer. Aborting.\n");
        exit(EXIT_FAILURE);
    }
    if (bufsize == 1) {
        fprintf(stderr, "Need space to terminate buffered string with \\0. Aborting.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Bufsize %d requested.\n", bufsize);

    char(*buf)[bufsize] = malloc(bufsize * sizeof(char));
    if (buf == NULL) {
        fprintf(stderr, "Encountered error while allocating memory for buffer.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "%s", my_fgets(bufsize, buf, stdin));
    free(buf);
    return EXIT_SUCCESS;
}
