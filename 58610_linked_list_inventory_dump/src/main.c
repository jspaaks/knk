#include "readline.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

constexpr static int NAME_LEN = 25;
static char * db_filename = "inventory.dat";

typedef struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part * next;
} Part;    

Part * inventory = nullptr;

void dump (void);
Part * find_part (int number);
void insert (void);
void print (void);
void prompt (void);
void restore (void);
void search (void);
void update (void);

void dump (void) {
    fprintf(stdout, " -- Dumping...\n");
    FILE * fp = fopen(db_filename, "wb+");
    Part * p = inventory;
    while (p != nullptr) {
        {
            int nwritten = fwrite(&p->number, sizeof(p->number), 1, fp);
            if (nwritten != 1 && ferror(fp)) {
                fclose(fp);
                fprintf(stderr, " -- Error writing to file '%s': %s.\n", db_filename, strerror(errno));
                errno = 0;
                exit(EXIT_FAILURE);
            }
        }
        {
            int nwritten = fwrite(&p->name, sizeof(p->name), 1, fp);
            if (nwritten != 1 && ferror(fp)) {
                fclose(fp);
                fprintf(stderr, " -- Error writing to file '%s': %s.\n", db_filename, strerror(errno));
                errno = 0;
                exit(EXIT_FAILURE);
            }
        }
        {
            int nwritten = fwrite(&p->on_hand, sizeof(p->on_hand), 1, fp);
            if (nwritten != 1 && ferror(fp)) {
                fclose(fp);
                fprintf(stderr, " -- Error writing to file '%s': %s.\n", db_filename, strerror(errno));
                errno = 0;
                exit(EXIT_FAILURE);
            }
        }
        p = p->next;
    }
    fclose(fp);
    fprintf(stdout, " -- Done.\n");
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
    Part * new = malloc(sizeof(Part) * 1);
    if (new == nullptr) {
        fprintf(stdout, " -- Database full; can't add any more parts.\n");
        return;
    }
    fprintf(stdout, " -- Enter part number: ");
    scanf("%d", &new->number);
    Part * cur = inventory;
    Part * prev = nullptr;
    while (cur != nullptr && new->number > cur->number) {
        prev = cur;
        cur = cur->next;
    }
    if (cur != nullptr && new->number == cur->number) {
        fprintf(stdout, " -- Part already exists.\n");
        free(new);
        return;
    }
    fprintf(stdout, " -- Enter part name: ");
    read_line(new->name, NAME_LEN);
    fprintf(stdout, " -- Enter quantity on hand: ");
    scanf("%d", &new->on_hand);
    new->next = cur;
    if (prev == nullptr) {
        inventory = new;
    } else {
        prev->next = new;
    }
}

int main (int, char **) {

    char code;
    for (;;) {
        prompt();
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
                fprintf(stdout, " -- Quitting.\n");
                return 0;
            case 'r':
                restore();
                break;
            default:
                printf(" -- Illegal code\n");
        }
        fprintf(stdout, "\n");
    }

    return EXIT_SUCCESS;
}

void print (void) {
    Part * p = inventory;
    if (p != nullptr) {
        fprintf(stdout, " -- Part number   Part name                   "
           "Quantity on hand\n");
    } else {
        fprintf(stdout, " -- <Empty>\n");
    }
    while (p != nullptr) {
        fprintf(stdout, " -- %7d       %-25s%11d\n", p->number, p->name, p->on_hand);
        p = p->next;
    }
}

void prompt (void) {
    char * operations[] = {
        "\x1b[4md\x1b[0mump",
        "\x1b[4mi\x1b[0mnsert",
        "\x1b[4mr\x1b[0mestore",
        "\x1b[4ms\x1b[0mearch",
        "\x1b[4mu\x1b[0mpdate",
        "\x1b[4mp\x1b[0mrint",
        "\x1b[4mq\x1b[0muit",
    };
    constexpr size_t n = sizeof(operations) / sizeof(operations[0]);
    fprintf(stdout, "Enter operation code (");
    for (size_t i = 0; i < n; ++i) {
        fprintf(stdout, "%s%s", operations[i], i + 1 < n ? ", ": "): ");
    }
}

void restore (void) {
    fprintf(stdout, " -- Restoring...\n");
    FILE * fp = fopen(db_filename, "rb");
    if (fp == nullptr) {
        fprintf(stderr, " -- Error opening file '%s': %s.\n", db_filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }
    Part * prev = nullptr;
    while (true) {
        Part * new = malloc(sizeof(Part) * 1);
        if (new == nullptr) {
            fprintf(stdout, " -- Database full; can't add any more parts.\n");
            return;
        }
        {
            int nread = fread(&new->number, sizeof(new->number), 1, fp);
            if (nread != 1 && ferror(fp)) {
                fprintf(stderr, " -- Error reading from file '%s': %s.\n", db_filename, strerror(errno));
                errno = 0;
                exit(EXIT_FAILURE);
            }
            if (nread != 1 && feof(fp)) {
                break;
            }
        }
        {
            int nread = fread(&new->name, sizeof(new->name), 1, fp);
            if (nread != 1 && ferror(fp)) {
                fprintf(stderr, " -- Error reading from file '%s': %s.\n", db_filename, strerror(errno));
                errno = 0;
                exit(EXIT_FAILURE);
            }
            if (nread != 1 && feof(fp)) {
                break;
            }
        }
        {
            int nread = fread(&new->on_hand, sizeof(new->on_hand), 1, fp);
            if (nread != 1 && ferror(fp)) {
                fprintf(stderr, " -- Error reading from file '%s': %s.\n", db_filename, strerror(errno));
                errno = 0;
                exit(EXIT_FAILURE);
            }
            if (nread != 1 && feof(fp)) {
                break;
            }
        }
        new->next = nullptr;
        if (prev == nullptr) {
            inventory = new;
        } else {
            prev->next = new;
        }
        prev = new;
    }
    fclose(fp);
    fprintf(stdout, " -- Done.\n");
}

void search (void) {
    int number;
    fprintf(stdout, " -- Enter part number: ");
    scanf("%d", &number);
    Part * p = find_part(number);
    if (p != nullptr) {
        fprintf(stdout, " -- Part name: %s\n", p->name);
        fprintf(stdout, " -- Quantity on hand: %d.\n", p->on_hand);
    } else {
        fprintf(stdout, " -- Part not found.\n");
    }
}

void update (void) {
    int number;
    fprintf(stdout, " -- Enter part number: ");
    scanf("%d", &number);
    Part * p = find_part(number);
    if (p != nullptr) {
        fprintf(stdout, " -- Enter change in quanity on hand: ");
        int change;
        scanf("%d", &change);
        p->on_hand += change;
    } else {
        fprintf(stdout, " -- Part not found.\n");
    }
}
