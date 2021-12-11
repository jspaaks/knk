#include <stdio.h>

int main (void) {

    int phone_number_part1;
    int phone_number_part2;
    int phone_number_part3;

    printf("Please enter a phone number [(xxx) xxx-xxxx]: ");
    scanf(" ( %d ) %d - %d", &phone_number_part1, &phone_number_part2, &phone_number_part3);
    printf("You entered: %d.%d.%d\n", phone_number_part1, phone_number_part2, phone_number_part3);

    return 0;

}
