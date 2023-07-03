#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int mm;
    int dd;
    int yyyy;
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%02d/%02d/%4d", &mm, &dd, &yyyy);
    const char *months[] = {
        "", "January", "February", "March", "April", "May",
        "June", "July", "August", "September", "October",
        "November", "December"
    };
    printf("You entered the date: %s %d, %d\n", months[mm], dd, yyyy);
    return EXIT_SUCCESS;
}
