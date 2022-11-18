#include <string.h>
#include <stdio.h>

int main (void) {
    char str[] = "------------------------------------------";
    printf("%s\n", str);
    strcpy(str, "tire-bouchon");
    printf("%s\n", str);
    strcpy(&str[4], "d-or-wi");
    printf("%s\n", str);
    strcat(str, "red");
    printf("%s\n", str);
}
