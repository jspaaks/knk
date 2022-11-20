#include <stdio.h>

int count_spaces(const char *s);

int count_spaces(const char *s) {
    int nspaces = 0;
    for (; *s != '\0'; s++) {
        if (*s == ' ') {
            nspaces++;
        }
    }
    return nspaces;
}

int main (void) {
    char s[] = " hello world ";
    int nspaces = count_spaces(s);
    printf("There are %d spaces in the string '%s'\n", nspaces, s);
}
