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

    fprintf(stdout, "Program to demonstrate printing code points beyond\n"
                    "ASCII but still within Latin-1 Extended.\n");
    fprintf(stdout, " -- d\xE9j\xE0 vu\n");
    fprintf(stdout, " -- C\xF4te d'Azur\n");
    fprintf(stdout, " -- cr\xE8me br\xFBl\xE9"
                    "e*\n");
    fprintf(stdout, " -- cr\xE8me fra\xEE"
                    "che*\n");
    fprintf(stdout, " -- Fahrvergn\xFCgen\n");
    fprintf(stdout, " -- t\xE8te \xE1 t\xE8te\n");
    fprintf(stdout, "Used code page from https://en.wikipedia.org/wiki/Latin-1_Supplement to encode this.\n");
    fprintf(stdout, "* Required string splitting.\n");
    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "demo";
    fprintf(stream,
            "Usage: %s\n"
            "    Program to demonstrate printing code points beyond\n"
            "    ASCII but still within Latin-1 Extended.\n",
            exename);
}
