#include "readline.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;
const char * db_filename = "inventory.bin";

void dump (void);
int find (int);
void insert (void);
void restore (void);
void search (void);
void update (void);
void print (void);

void dump (void) {
    FILE * fp = fopen(db_filename, "wb+");
    if (fp == nullptr) {
        fprintf(stderr, "Error writing to file '%s': %s.\n", db_filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }

    size_t actual = fwrite(&inventory, sizeof(struct part), num_parts, fp);
    size_t expected = num_parts;
    if (actual < expected && ferror(fp)) {
        fprintf(stderr, "Error writing to file '%s': %s.\n", db_filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "Dumped database contents to file '%s'.\n", db_filename);

    int status = fclose(fp);
    if (status == EOF) {
        fprintf(stderr, "Error closing file '%s': %s.\n", db_filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }
}

int find (int number) {
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

    if (find(part_number) >= 0) {
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
    char code;

    for (;;) {
        printf("Enter one-letter operation code [\x1b[4md\x1b[0mump, \x1b[4mi\x1b[0mnsert, \x1b[4mr\x1b[0mestore, "
               "\x1b[4ms\x1b[0mearch, \x1b[4mu\x1b[0mpdate, \x1b[4mp\x1b[0mrint, \x1b[4mq\x1b[0muit]: ");
        scanf(" %c", &code);
        while (getchar() != '\n') {
            ;
        }
        switch (code) {
            case 'd': {
                dump();
                break;
            }
            case 'i': {
                insert();
                break;
            }
            case 'r': {
                restore();
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
                fprintf(stderr, "Unknown code '%c'.\n", code);
                break;
            }
        }
    }
}

void restore (void) {
    FILE * fp = fopen(db_filename, "rb");
    if (fp == nullptr) {
        fprintf(stderr, "Error opening file '%s': %s.\n", db_filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "Restored database contents from file '%s'.\n", db_filename);

    num_parts = 0;
    struct part * p = &inventory[0];
    while (true) {
        size_t nread = fread(p, sizeof(struct part), 1, fp);
        if (nread != 1 && ferror(fp)) {
            fprintf(stderr, "Error reading file '%s': %s.\n", db_filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        if (nread != 1 && feof(fp)) {
            break;
        }
        num_parts += 1;
        p++;
    }

    int status = fclose(fp);
    if (status == EOF) {
        fprintf(stderr, "Error closing file '%s': %s.\n", db_filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }
}

void search (void) {
    int i, number;
    printf("Enter part number: ");
    scanf("%d", &number);
    i = find(number);
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
    i = find(number);
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
        printf("%7d       %-25s%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
    }
}
