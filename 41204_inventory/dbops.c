#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dbops.h"
#include "readline.h"


void update_on_hand (Part (*)[], int i);
void update_price (Part (*)[], int i);


int find_part (const int * num_parts, Part (* inventory)[], const int number) {
    for (int i = 0; i < *num_parts; i++) {
        if ((*inventory)[i].number == number) {
            return i;
        }
    }
    return -1;
}


void insert (int * num_parts, Part (* inventory)[], const int max_parts) {
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

    printf("┃  Enter price: ");
    scanf("%d", &new.price);

    int i = *num_parts;
    while (i > 0 && (*inventory)[i - 1].number > new.number) {
        (*inventory)[i] = (*inventory)[i - 1];
        i--;
    }
    (*inventory)[i] = new;
    (*num_parts)++;
    printf("┗━ Part added.\n");
}


void search (const int * num_parts, Part (* inventory)[]) {
    int i;
    int number;
    printf("┃  Searching...\n");
    if (*num_parts == 0) {
        printf("┗━ Database empty.\n");
        return;
    }

    printf("┃  Enter part number: ");
    scanf("%d", &number);
    i = find_part(num_parts, inventory, number);
    if (i >= 0) {
        printf("┃  Part name        : %s\n", (*inventory)[i].name);
        printf("┃  Quantity on hand : %d\n", (*inventory)[i].on_hand);
        printf("┃  Price            : %d\n", (*inventory)[i].price);
        printf("┗━ Search complete.\n");
    } else {
        printf("┗━ Part not found.\n");
    }
}


void update (const int * num_parts, Part (* inventory)[]) {
    printf("┃  Updating...\n");
    if (*num_parts == 0) {
        printf("┗━ Database empty.\n");
        return;
    }
    printf("┃  Enter part number: ");
    int number;
    scanf("%d", &number);
    int i = find_part(num_parts, inventory, number);
    if (i >= 0) {
        update_on_hand(inventory, i);
        update_price(inventory, i);
        printf("┗━ Database updated.\n");
    } else {
        printf("┗━ Part not found.\n");
    }
}


void update_on_hand (Part (* inventory)[], int i) {
    printf("┃  Do you want to change the 'on_hand' value [y/n]?: ");
    char answer;
    scanf(" %c", &answer);
    if (answer == 'y') {
        int new;
        printf("┃  Enter new value for on_hand: ");
        scanf("%d", &new);
        (*inventory)[i].on_hand = new;
    }
}


void update_price (Part (* inventory)[], int i) {
    printf("┃  Do you want to change the price [y/n]?: ");
    char answer;
    scanf(" %c", &answer);
    if (answer == 'y') {
        int new;
        printf("┃  Enter new value for price: ");
        scanf("%d", &new);
        (*inventory)[i].price = new;
    }
}


void print (const int * num_parts, Part (* inventory)[]) {
    printf("┃  Printing...\n");
    if (*num_parts == 0) {
        printf("┗━ Database empty.\n");
        return;
    }
    char fmt1[100];
    char fmt2[100];
    sprintf(fmt1, "┃  Part Number   %%-%dsQuantity on Hand   Price\n", NAME_LEN);
    printf(fmt1, "Part Name");
    sprintf(fmt2, "┃  %%-13d %%-%ds%%-16d   %%d\n", NAME_LEN);
    for (int i = 0; i < *num_parts; i++) {
        printf(fmt2, (*inventory)[i].number,
                     (*inventory)[i].name,
                     (*inventory)[i].on_hand,
                     (*inventory)[i].price);
    }
    printf("┗━ Done.\n");
}
