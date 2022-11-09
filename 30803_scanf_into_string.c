#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int i;
    int j;
    char s[100];

    printf("Enter the characters between the brackets exactly as-is <12abc34 56def78>:\n");
    scanf("%d%s%d", &i, s, &j);
    printf("i = %d\n", i);
    printf("s = %s\n", s);
    printf("j = %d\n", j);

    return EXIT_SUCCESS;
}
