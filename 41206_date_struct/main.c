#include <stdio.h>
#include <assert.h>
#include "dates.h"

void get_date (Date *); 


void get_date (Date * d) {
    scanf(" %2d / %2d / %4d", &(*d).month, &(*d).day, &(*d).year);
    assert(1 <= (*d).day && (*d).day <= 31 && "day integer not from range [1..31]");
    assert(1 <= (*d).month && (*d).month <= 12 && "month integer not from range [1..12]");
}


int main (void) {

    Date d1;
    Date d2;

    printf("Enter first date (mm/dd/yyyy): ");
    get_date(&d1);
    int doy1 = day_of_year(d1);


    printf("Enter second date (mm/dd/yyyy): ");
    get_date(&d2);
    int doy2 = day_of_year(d2);

    printf("day of year for %d-%d-%d is: %d\n", d1.day, d1.month, d1.year, doy1);
    printf("day of year for %d-%d-%d is: %d\n", d2.day, d2.month, d2.year, doy2);

    int diff = compare_dates(d1, d2);
    if (diff == -1) {
        printf("%d-%d-%d is before %d-%d-%d\n", d1.day, d1.month, d1.year, d2.day, d2.month, d2.year);
    } else if (diff == 0) {
        printf("%d-%d-%d is the same as %d-%d-%d\n", d1.day, d1.month, d1.year, d2.day, d2.month, d2.year);
    } else {
        printf("%d-%d-%d is after %d-%d-%d\n", d1.day, d1.month, d1.year, d2.day, d2.month, d2.year);
    }

}
