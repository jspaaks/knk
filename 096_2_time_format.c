#include <stdio.h>

int main (void) {

    int hh24, mm;

    printf("Enter a time in 24-hour format (hh:mm): ");
    scanf(" %2d : %2d", &hh24, &mm);

    int hh12 = hh24 % 12;
    printf("Equivalent time in 12-hour format     : %02d:%02d %cM\n", hh12 == 0 ? 12 : hh12, mm, hh24 >= 12 ? 'P' : 'A');

    return 0;

}
