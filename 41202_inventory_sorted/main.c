#include <stdio.h>
#include <stdlib.h>
#include "dbops.h"


int main (void) {
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
                fprintf(stderr, "┗━ Unknown code '%c'. Use 'q' to quit.\n", code);
                break;
            }
        }
    }
}
