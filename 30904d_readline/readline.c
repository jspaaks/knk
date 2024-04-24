#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define NSTRINGS 6
#define STRINGLEN 10

int read_line(char str[], int n);

int main (void) {

    char strings[NSTRINGS][STRINGLEN + 1];
    char *p = &strings[0][0];
    char *q = &strings[NSTRINGS - 1][0];
    int n = 0;
    bool termination = false;

    printf("Enter a couple of strings:\n");
    do {
        termination = read_line(p, STRINGLEN) == STRINGLEN || termination;
        if (strcmp(p, "") == 0) {
            break;
        }
        n++;
        p += STRINGLEN + 1;
    } while (p <= q);

    if (p > q) {
        printf("Memory full.\n");
    } else {
        printf("End of input detected.\n");
    }

    if (termination == true) {
        printf("Some input after character position %d may have been discarded.\n", STRINGLEN - 1);
    }

    printf("Here's what I recorded:\n");
    for (int i = 0; i < n; i++) {
        printf("%2d: %s\n", i, strings[i]);
    }
    return EXIT_SUCCESS;
}


int read_line(char str[], int n) {
    int ch, i = 0;
    while (true) {
        ch = getchar();
        if (ch == '\n') {
            break;
        }
        if (i < n) {
            str[i] = ch;
            i++;
        }
    }
    str[i] = '\0';
    return i;
}
