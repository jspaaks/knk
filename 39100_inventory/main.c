#include <stdio.h>
#include <stdlib.h>
//#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100


struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;


int find_part (int);
void insert (void);
void search (void);
void update (void);
void print (void);


int find_part (int number) {
    for (int i = 0; i < num_parts; i++) {
        if (inventory[i].number == number) {
            return i;
        }
    }
    return -1;
}


void insert (void) {
}

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
                fprintf(stderr, "Unknown code '%c'. Use 'q' to quit.\n", code);
                break;
            }
        }
    }
}


void search (void) {
}


void update (void) {
}


void print (void) {
}

