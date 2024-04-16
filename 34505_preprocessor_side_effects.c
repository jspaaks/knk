#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef TOUPPER
#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))
#endif

int main(void) {
    char s[4+1];
    int i;

    strcpy(s, "abcd");
    i = 0;
    putchar(TOUPPER(s[++i]));

    strcpy(s, "0123");
    i = 0;
    putchar(TOUPPER(s[++i]));

    printf("\n");
    printf("'a' <= '1'? %s\n", 'a' <= '1' ? "true" : "false");

    return EXIT_SUCCESS;
}
