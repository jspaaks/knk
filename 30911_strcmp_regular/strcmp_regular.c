#include <stdio.h>

int my_strcmp(char *, char *);

int main (void) {
    char s0[10] = "z";
    char s1[10] = "zzzzz";
    int result = my_strcmp(s0, s1);
    printf("%d\n", result);
}

int my_strcmp(char *s, char *t) {
    int i = 0;
    for (; s[i] == t[i]; i++) {
        if (s[i] == '\0') {
            return 0;
        }
    }
    return s[i] - t[i];
}
