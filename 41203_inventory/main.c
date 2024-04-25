#include <stdio.h>
#include <stdlib.h>
#include "dbops.h"

#define MAX_PARTS 100


int main (void) {
    Part inventory[MAX_PARTS];
    int num_parts = 0;
    char code;

    for (;;) {
        printf("Enter operation code [i,s,u,p,q]: ");
        scanf(" %c", &code);
        while (getchar() != '\n') {
            ;
        }
        switch (code) {
            case 'i': {
                insert(&num_parts, &inventory, MAX_PARTS);
                break;
            }
            case 's': {
                search(&num_parts, &inventory);
                break;
            }
            case 'u': {
                update(&num_parts, &inventory);
                break;
            }
            case 'p': {
                print(&num_parts, &inventory);
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
