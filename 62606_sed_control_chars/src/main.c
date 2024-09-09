#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_usage (FILE * stream);

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 1) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    while (true) {
        int ch = fgetc(stdin);
        if (ch == EOF && ferror(stdin)) {
            fprintf(stderr, "Error reading from STDIN: %s.\n", strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        if (ch == EOF && feof(stdin)) {
            break;
        }

        if (iscntrl(ch) && ch != '\n') {
            fputc('?', stdout);
        } else {
            fputc(ch, stdout);
        }
    }

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "showctrlchrs";
    fprintf(stream,
            "Usage: %s\n"
            "   Copy STDIN to STDOUT while replacing any control\n"
            "   characters except '\\n' with '?'.\n",
            exename);
}
