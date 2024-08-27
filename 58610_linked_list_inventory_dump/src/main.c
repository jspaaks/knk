#include "readline.h"
#include <stdio.h>
#include <stdlib.h>

constexpr int NAME_LEN = 25;

typedef struct part Part;

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part * next;
};

Part * inventory = nullptr;

void dump (void);
Part * find_part (int number);
void insert (void);
void print (void);
void restore (void);
void search (void);
void update (void);

void dump (void) {
    fprintf(stdout, "Dumping.\n");
}

Part * find_part (int number) {
    Part * p = inventory;
    while (p != nullptr && number > p->number) {
        p = p->next;
    }
    if (p != nullptr && number == p->number) {
        return p;
    }
    return nullptr;
}

void insert (void) {
    Part * new_node = malloc(sizeof(struct part));
    if (new_node == nullptr) {
        printf("Database full; can't add any more parts.\n");
        return;
    }
    printf("Enter part number: ");
    scanf("%d", &new_node->number);
    Part * cur = inventory;
    Part * prev = nullptr;
    while (cur != nullptr && new_node->number > cur->number) {
        prev = cur;
        cur = cur->next;
    }
    if (cur != nullptr && new_node->number == cur->number) {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }
    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);
    new_node->next = cur;
    if (prev == nullptr) {
        inventory = new_node;
    } else {
        prev->next = new_node;
    }
}

int main (int, char **) {

    char code;
    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (true) {
            if (getchar() == '\n') break;
        }
        switch (code) {
            case 'd':
                dump();
                break;
            case 'i':
                insert();
                break;
            case 's':
                search();
                break;
            case 'u':
                update();
                break;
            case 'p':
                print();
                break;
            case 'q':
                return 0;
            default:
                printf("Illegal code\n");
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}

void print (void) {
    printf("Part number   Part name                   "
           "Quantity on hand\n");
    Part * p = inventory;
    while (p != nullptr) {
        printf("%7d       %-25s%11d\n", p->number, p->name, p->on_hand);
        p = p->next;
    }
}

void search (void) {
    int number;
    printf("Enter part number: ");
    scanf("%d", &number);
    Part * p = find_part(number);
    if (p != nullptr) {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d.\n", p->on_hand);
    } else {
        printf("Part not found.\n");
    }
}

void update (void) {
    int number;
    printf("Enter part number: ");
    scanf("%d", &number);
    Part * p = find_part(number);
    if (p != nullptr) {
        printf("Enter change in quanity on hand: ");
        int change;
        scanf("%d", &change);
        p->on_hand += change;
    } else {
        printf("Part not found.\n");
    }
}
