#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY '&'

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

    char orig_char;
    char new_char;

    /*
    while ((orig_char = getchar()) != EOF) {
        new_char = orig_char ^ KEY;
        if (isprint(orig_char) && isprint(new_char))
            putchar(new_char);
        else
            putchar(orig_char);
    }
    */

    while ((orig_char = getchar()) != EOF) ??<
        new_char = orig_char ??' KEY;
        if (isprint(orig_char) && isprint(new_char))
            putchar(new_char);
        else
            putchar(orig_char);
    ??>
    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "trigraphs";
    fprintf(stream,
            "Usage: %s\n"
            "    Program to demonstrate trigraphs.\n",
            exename);
}

