#include <stdio.h>
#include <string.h>

int main (void) {
    char s1[16];
    char s2[16];

    strcpy(s1, "computer");
    strcpy(s2, "science");

    if (strcmp(s1, s2) < 0) {
        strcat(s1, s2);
    } else {
        strcat(s2, s1);
    }
    int i = strlen(s1) - 6;
    s1[i] = '\0';
    printf("%s\n", s1);
    printf("%s\n", &s1[++i]);
}
