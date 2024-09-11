#include "inventory.h"
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

    char code;

    for (;;) {
        printf("Enter operation code [i,s,u,p,q]: ");
        scanf(" %c", &code);
        while (getchar() != '\n') {
            ;
        }
        switch (code) {
            case 'i': {
                insert();
                break;
            }
            case 's': {
                search();
                break;
            }
            case 'u': {
                update();
                break;
            }
            case 'p': {
                print();
                break;
            }
            case 'q': {
                return EXIT_SUCCESS;
            }
            default: {
                fprintf(stderr, "Unknown code '%c'. Use 'q' to quit.\n", code);
                break;
            }
        }
    }

    

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "inventory";
    fprintf(stream, "Usage: %s\n", exename);
}

