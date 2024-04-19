#include <stdio.h>
#include "readline.h"


int read_line(char str[], int n) {
    int ch = 0;
    int i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < n) {
            str[i] = ch;
            i++;
        }
    }
    str[i] = '\0';
    return i;
}
