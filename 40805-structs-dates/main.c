#include <stdio.h>
#include <stdbool.h>


struct date {
    int day;
    int month;
    int year;
};


int compare_dates(struct date, struct date);
int day_of_year (struct date);


int compare_dates(struct date d1, struct date d2) {
    if (d1.year < d2.year) {
        return -1;
    } else if (d1.year == d2. year) {
        int doy1 = day_of_year(d1);
        int doy2 = day_of_year(d2);
        if (doy1 < doy2) {
            return -1;
        } else if (doy1 == doy2) {
            return 0;
        } else {
            return 1;
        }
    } else {
        return 1;
    }
}


int day_of_year (struct date d) {

    typedef struct {
        char name[15];
        int len;
    } Month;

    bool isleap = d.year % 4 == 0;

    Month months[12] = {
        {"January", 31},
        {"February", isleap ? 29 : 28},
        {"March", 31},
        {"April", 30},
        {"May", 31},
        {"June", 30},
        {"July", 31},
        {"August", 31},
        {"September", 30},
        {"October", 31},
        {"November", 30},
        {"December", 31}
    };

    int doy = 0;
    for (int i = 0; i < d.month - 1; i++) {
        doy += months[i].len;
    }
    return doy += d.day;

}


int main (void) {
    struct date d1 = {.day = 6, .month = 7, .year = 2024};
    struct date d2 = {.day = 6, .month = 7, .year = 2023};
    int doy1 = day_of_year(d1);
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


