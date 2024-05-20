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

int comparator (const void *, const void *);
int find_part (int);
void create (void);
void erase (void);
void grow_memory (void);
void insert (void);
void print (void);
void search (void);
void update (void);

int comparator (const void * this, const void * other ) {
    struct part * this0 = (struct part *) this;
    struct part * other0 = (struct part *) other;
    if (this0->number < other0->number) {
        return -1;
    } else if (this0->number == other0->number) {
        return 0;
    } else {
        return 1;
    }
}

void create (void) {
    inventory = malloc(num_parts_max * sizeof(struct part));
    if (inventory == NULL) {
        fprintf(stderr, "Something went wrong allocating memory for the inventory.\n");
        exit(EXIT_FAILURE);
    }
}

void erase (void) {

    int part_number;

    fprintf(stdout, "  Enter part number that you want to erase: ");
    scanf("%d", &part_number);

    int irow = find_part(part_number);
    if (irow == -1) {
        fprintf(stderr, "  Can't erase a part that doesn't exist.\n\n");
        return;
    }
    for (; irow < num_parts - 1; irow++) {
        inventory[irow] = inventory[irow + 1];
    }
    num_parts -= 1;
    fprintf(stdout, "  Erased part %d.\n", part_number);
}

int find_part (int number) {
    for (int i = 0; i < num_parts; i++) {
        if (inventory[i].number == number) {
            return i;
        }
    }
    return -1;
}

void grow_memory (void) {
    num_parts_max *= 2;
    inventory = realloc(inventory, num_parts_max * sizeof(struct part));
    if (inventory == NULL) {
        fprintf(stderr, "Something went wrong allocating memory for the inventory.\n");
        exit(EXIT_FAILURE);
    }
}

void insert (void) {
    int part_number;

    if (num_parts == num_parts_max) {
        grow_memory();
    }

    fprintf(stdout, "  Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(part_number) >= 0) {
        fprintf(stdout, "  Part already exists.\n");
        return;
    }

    inventory[num_parts].number = part_number;
    fprintf(stdout, "  Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    fprintf(stdout, "  Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
    num_parts++;
    fprintf(stdout, "  Inserted part %d.\n\n", part_number);
}

int main (void) {

    create();

    char code;

    for (;;) {
        fprintf(stdout, "Enter operation code [e,i,p,q,s,u]: ");
        scanf(" %c", &code);
        while (getchar() != '\n') {
            ;
        }
        switch (code) {
            case 'e': {
                erase();
                break;
            }
            case 'i': {
                insert();
                break;
            }
            case 'p': {
                print();
                break;
            }
            case 'q': {
                return EXIT_SUCCESS;
            }
            case 's': {
                search();
                break;
            }
            case 'u': {
                update();
                break;
            }
            default: {
                fprintf(stderr, "Unknown code '%c'. Use 'q' to quit.\n", code);
                break;
            }
        }
    }
    exit(EXIT_SUCCESS);
}

void print (void) {
    int i;
    qsort(inventory, num_parts, sizeof(struct part), comparator);
    fprintf(stdout, "  Part Number   Part Name                          "
           "Quantity on Hand\n");
    for (i = 0; i < num_parts; i++) {
        fprintf(stdout, "  %7d       %-25s%11d\n", inventory[i].number,
               inventory[i].name, inventory[i].on_hand);
    }
    fprintf(stdout, "\n");
}

void search (void) {
    int i, number;
    fprintf(stdout, "  Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        fprintf(stdout, "  Part name: %s\n", inventory[i].name);
        fprintf(stdout, "  Quantity on hand: %d\n\n", inventory[i].on_hand);
    } else {
        fprintf(stdout, "  Part not found.\n\n");
    }
}

void update (void) {
    int i, number, change;
    fprintf(stdout, "  Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        fprintf(stdout, "  Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
        fprintf(stdout, "  Updated on hand for part %d.\n\n", number);
    } else {
        fprintf(stdout, "  Part not found.\n\n");
    }
}
