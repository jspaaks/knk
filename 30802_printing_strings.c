#include <stdio.h>
#include <stdlib.h>

int main (void) {

    char *p = "abc";

    // printf("<a>");
    // putchar(p);
    // printf("</a>\n");

    printf("<b>");
    putchar(*p);
    printf("</b>\n");

    printf("<c>");
    puts(p);
    printf("</c>\n");

    // printf("<d>");
    // puts(*p);
    // printf("</d>\n");

    return EXIT_SUCCESS;
}
