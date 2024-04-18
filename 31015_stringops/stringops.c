#include <stdio.h>

int f(char *s, char *t);


int f(char *s, char *t) {
    // return the position of the first character
    // from s that doesn't also occur in t
    char *p1, *p2;
    for (p1 = s; *p1; p1++) {
        for (p2 = t; *p2; p2++) {
            if (*p1 == *p2) {
                break;
            }
        }
        if (*p2 == '\0') {
            break;
        }
    }
    return p1 - s;
}

int main (void) {
    int r0 = f("abcd", "babc");
    printf("f(\"abcd\", \"babc\"): %d\n", r0);

    int r1 = f("abcd", "bcd");
    printf("f(\"abcd\", \"bcd\"): %d\n", r1);
}
