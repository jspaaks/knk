#include <stdio.h>


int main (void) {


    printf("This program displays the bit size of various types on this machine.\n");
    printf("Type        | bits\n");
    printf("-----------   ----\n");
    printf("short       | %zu\n", sizeof(short) * 8);
    printf("int         | %zu\n", sizeof(int) * 8);
    printf("long        | %zu\n", sizeof(long) * 8);
    printf("float       | %zu\n", sizeof(float) * 8);
    printf("double      | %zu\n", sizeof(double) * 8);
    printf("long double | %zu\n", sizeof(long double) * 8);

    return 0;

}
