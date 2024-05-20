#include "readline.h"
#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25
#define NUM_PARTS_MAX_INIT 4

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

struct part * inventory = NULL;
int num_parts = 0;
int num_parts_max = NUM_PARTS_MAX_INIT;

void create (void);
int find_part (int);
void grow_memory (void);
void insert (void);
void search (void);
void update (void);
void print (void);

void create (void) {
    inventory = malloc(num_parts_max * sizeof(struct part));
    if (inventory == NULL) {
        fprintf(stderr, "Something went wrong allocating memory for the inventory.\n");
        exit(EXIT_FAILURE);
    }
}

void grow_memory (void) {
    num_parts_max *= 2;
    inventory = realloc(inventory, num_parts_max * sizeof(struct part));
    if (inventory == NULL) {
        fprintf(stderr, "Something went wrong allocating memory for the inventory.\n");
        exit(EXIT_FAILURE);
    }
}

int find_part (int number) {
    for (int i = 0; i < num_parts; i++) {
        if (inventory[i].number == number) {
            return i;
        }
    }
    return -1;
}

void insert (void) {
    int part_number;

    if (num_parts == num_parts_max) {
        grow_memory();
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(part_number) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    inventory[num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
    num_parts++;
}

int main (void) {

    create();

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
    exit(EXIT_SUCCESS);
}

void search (void) {
    int i, number;
    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    } else {
        printf("Part not found.\n");
    }
}

void update (void) {
    int i, number, change;
    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    } else {
        printf("Part not found.\n");
    }
}

void print (void) {
    int i;
    printf("Part Number   Part Name                          "
           "Quantity on Hand\n");
    for (i = 0; i < num_parts; i++) {
        printf("%7d       %-25s%11d\n", inventory[i].number,
               inventory[i].name, inventory[i].on_hand);
    }
}
