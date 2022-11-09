#include <stdio.h>
#include <stdlib.h>

int main (void) {

    printf("<a>");
    printf("%c", '\n');
    printf("</a>\n");

    printf("<d>");
    printf("%s", "\n");
    printf("</d>\n");

    printf("<f>");
    printf("\n");
    printf("</f>\n");

    printf("<g>");
    putchar('\n');
    printf("</g>\n");

    printf("<k>");
    puts("");
    printf("</k>\n");

    //printf("%c", "\n");
    //printf("%s", '\n');
    //printf('\n');
    //putchar("\n");
    //puts('\n');
    //puts("\n"); // but prints two newlines

    return EXIT_SUCCESS;
}
