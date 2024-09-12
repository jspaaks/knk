#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_usage (FILE * stream);

static const char * msg = "Program to demonstrate printing code points in the range 0x80-0xFF.";

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 1) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "%s\n", msg);
    fprintf(stdout, " -- d\xC3\xA9j\xC3\xA0 vu\n");
    fprintf(stdout, " -- C\xC3\xB4te d'Azur\n");
    fprintf(stdout, " -- cr\xC3\xA8me br\xC3\xBBl\xC3\xA9"
                    "e*\n");
    fprintf(stdout, " -- cr\xC3\xA8me fra\xC3\xAE"
                    "che*\n");
    fprintf(stdout, " -- Fahrvergn\xC3\xBCgen\n");
    fprintf(stdout, " -- t\xC3\xA8te \xC3\xA1 t\xC3\xA8te\n");
    fprintf(stdout, "Used code page from https://www.charset.org/utf-8 to encode this.\n");
    fprintf(stdout, "* Required string splitting.\n");
    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "demo";
    fprintf(stream, "Usage: %s\n    %s\n", exename, msg);
}
