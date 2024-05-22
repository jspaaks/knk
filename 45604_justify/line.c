#include "line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 60

struct node {
    char * payload;
    struct node * next;
};

struct node * line = NULL;

int num_words = 0;

void clear_line (void) {
    struct node * i = line;
    while (i != NULL) {
        free(i->payload);
        struct node * tmp = i;
        i = i->next;
        free(tmp);
    }
    line = NULL;
    num_words = 0;
}

void add_word (const char * word) {
    // allocate memory, copy contents of word into it
    int nchars = strlen(word);
    char * mem_payload = malloc((nchars + 1) * sizeof(char));
    if (mem_payload == NULL) {
        fprintf(stderr, "Something went wrong allocating memory for new word.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(mem_payload, word, nchars + 1);

    // allocate memory for a new linked list item
    struct node * mem_node = malloc(1 * sizeof(struct node));
    if (mem_payload == NULL) {
        fprintf(stderr, "Something went wrong allocating memory for new linked list node.\n");
        exit(EXIT_FAILURE);
    }
    mem_node->payload = mem_payload;
    mem_node->next = NULL;
    if (line == NULL) {
        line = mem_node;
    } else {
        struct node * i = line;
        while (i->next != NULL) {
            i = i->next;
        }
        i->next = mem_node;
    }
    num_words++;
}

int space_remaining (void) {
    int rem = MAX_LINE_LEN;
    if (num_words > 0) {
        rem -= num_words - 1;
    }
    struct node * i = line;
    while (i != NULL) {
        rem -= strlen(i->payload);
        i = i->next;
    }
    return rem;
}

void write_line (void) {
    int spaces[(int) (MAX_LINE_LEN / 2)] = { 0 };
    for (int i = 0; i < num_words; i++) {
        spaces[i] = 1;
    }
    int rem = space_remaining();
    while (rem > 0) {
        int i = rand() % (num_words - 1);
        spaces[i]++;
        rem--;
    }

    struct node * inode = line;
    int iword = 0;
    while (inode != NULL) {
        fprintf(stdout, "%s", inode->payload);
        if (inode->next != NULL) {
            while (spaces[iword] > 0) {
                putchar(' ');
                spaces[iword]--;
            }
            iword++;
        }
        inode = inode->next;
    }
    fprintf(stdout, "|\n");
}

void flush_line (void) {
    if (num_words > 0) {
        struct node * i = line;
        while (i != NULL) {
            fprintf(stdout, "%s", i->payload);
            if (i->next != NULL) {
                putchar(' ');
            }
            i = i->next;
        }
        int rem = space_remaining();
        while (rem > 0) {
            putchar(' ');
            rem--;
        }
        putchar('|');
        putchar('\n');
    }
}
