#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void);
void capitalize(char *, const char *, int n);


int main(void) {
    char *s = "some kind of string with extra characters 2352 8836(&&";
    int n = strlen(s);
    char capitalized[n];
    capitalize(capitalized, s, n);
    puts(capitalized);
}

void capitalize(char *capitalized, const char *s, int n) {
    strncpy(capitalized, s, n);
    for (int i = 0; i < n; i++) {
        capitalized[i] = toupper(s[i]);
    }
}
