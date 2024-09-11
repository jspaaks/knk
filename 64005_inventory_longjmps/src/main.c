#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

static jmp_buf env;

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

int find_part (int);
void insert (void);
void search (void);
void show_usage (FILE *);
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
    int part_number;

    if (num_parts == MAX_PARTS) {
        printf("Database is full; Can't add any more parts.\n");
        return;
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
    longjmp(env, 1);
}

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

    if (setjmp(env) == 0) {
        // jump target has been set -- now jump to it.
        longjmp(env, 1);
    } else {
        for (;;) {
            printf("Enter operation code ["
            "\033[4mi\033[0mnsert, "
            "\033[4ms\033[0mearch, "
            "\033[4mu\033[0mpdate, "
            "\033[4mp\033[0mrint, "
            "\033[4mq\033[0muit]: ");
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
                }
            }
        }
    }
    return EXIT_SUCCESS;
}

void print (void) {
    int i;
    printf("Part Number   Part Name                          "
           "Quantity on Hand\n");
    for (i = 0; i < num_parts; i++) {
        printf("%7d       %-25s%11d\n", inventory[i].number,
               inventory[i].name, inventory[i].on_hand);
    }
    longjmp(env, 1);
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
    longjmp(env, 1);
}

void show_usage (FILE * stream) {
    char * exename = "inventory";
    fprintf(stream, "Usage: %s\n", exename);
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
    longjmp(env, 1);
}

