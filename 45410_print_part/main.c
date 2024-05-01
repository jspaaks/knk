#include <stdio.h>

#define NAME_LEN 25
#define INVENTORY_LEN 100

struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
};

void print_part (struct part *, int);

int main (void) {

    struct part inventory[INVENTORY_LEN] = {
        {
            .number = 123,
            .name = "first",
            .on_hand = 4,
        },
        {
            .number = 512,
            .name = "second",
            .on_hand = 7,
        },
    };
    int num_parts = 2;

    print_part(&inventory[0], num_parts);
}


void print_part (struct part * p, int n) {

    fprintf(stdout, "Part number    Part name                    Qty on hand\n");
    for (int i = 0; i < n; i++) {
        fprintf(stdout, "%-11d    %-25s    %-11d\n", (p + i)->number, (p + i)->name, (p + i)->on_hand);
    }
}
