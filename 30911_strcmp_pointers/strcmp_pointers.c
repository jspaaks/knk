#include <stdio.h>

int my_strcmp(char *, char *);

int main (void) {
    char s0[10] = "ab";
    char s1[10] = "aa";
    int result = my_strcmp(s0, s1);
    printf("%d\n", result);
}

int my_strcmp(char *s, char *t) {
    for (; *s == *t; s++, t++) {
        if (*s == '\0') {
            return 0;
        }
    }
    return *s - *t;
}
