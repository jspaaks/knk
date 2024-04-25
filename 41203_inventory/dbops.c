#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dbops.h"
#include "readline.h"


int find_part (int * num_parts, Part (* inventory)[], int number) {
    for (int i = 0; i < *num_parts; i++) {
        if ((*inventory)[i].number == number) {
            return i;
        }
    }
    return -1;
}


void insert (int * num_parts, Part (* inventory)[], int max_parts) {
    printf("┃  Inserting...\n");
    if (*num_parts == max_parts) {
        printf("┗━ Database is full; Can't add any more parts.\n");
        return;
    }

    Part new;
    printf("┃  Enter part number: ");
    scanf("%d", &new.number);

    if (find_part(num_parts, inventory, new.number) >= 0) {
        printf("┗━ Part already exists.\n");
        return;
    }

    printf("┃  Enter part name: ");
    read_line(new.name, NAME_LEN);
    printf("┃  Enter quantity on hand: ");
    scanf("%d", &new.on_hand);

    int i = *num_parts;
    while (i > 0 && (*inventory)[i - 1].number > new.number) {
        (*inventory)[i] = (*inventory)[i - 1];
        i--;
    }
    (*inventory)[i] = new;
    (*num_parts)++;
    printf("┗━ Part added.\n");
}


void search (int * num_parts, Part (* inventory)[]) {
    int i;
    int number;
    printf("┃  Searching...\n");
    printf("┃  Enter part number: ");
    scanf("%d", &number);
    i = find_part(num_parts, inventory, number);
    if (i >= 0) {
        printf("┃  Part name: %s\n", (*inventory)[i].name);
        printf("┃  Quantity on hand: %d\n", (*inventory)[i].on_hand);
        printf("┗━ Search complete.\n");
    } else {
        printf("┗━ Part not found.\n");
    }
}


void update (int * num_parts, Part (* inventory)[]) {
    printf("┃  Updating...\n");
    printf("┃  Enter part number: ");
    int number;
    scanf("%d", &number);
    int i = find_part(num_parts, inventory, number);
    if (i >= 0) {
        int change;
        printf("┃  Enter change in quantity on hand: ");
        scanf("%d", &change);
        (*inventory)[i].on_hand += change;
        printf("┗━ Database updated.\n");
    } else {
        printf("┗━ Part not found.\n");
    }
}


void print (int * num_parts, Part (* inventory)[]) {
    printf("┃  Printing...\n");
    if (*num_parts == 0) {
        printf("┗━ Database empty.\n");
        return;
    }
    char fmt1[100];
    char fmt2[100];
    sprintf(fmt1, "┃  Part Number   %%-%dsQuantity on Hand\n", NAME_LEN);
    printf(fmt1, "Part Name");
    sprintf(fmt2, "┃  %%-13d %%-%ds%%-16d\n", NAME_LEN);
    for (int i = 0; i < *num_parts; i++) {
        printf(fmt2, (*inventory)[i].number,
                     (*inventory)[i].name,
                     (*inventory)[i].on_hand);
    }
    printf("┗━ Done.\n");
}
