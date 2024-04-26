#include <stdio.h>
#include <stdbool.h>
#include "dates.h"


int compare_dates(Date d1, Date d2) {
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


int day_of_year (Date d) {

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
