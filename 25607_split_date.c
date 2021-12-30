#include <stdio.h>
#include <stdbool.h>


void split_date (int day_of_year, int year, int *month, int *day);

const int NMONTHS = 12;
const int MONTH_LENGTHS[2][12] = {
    { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};


int main (void) {

    int month;
    int day;

    for (int year = 1980; year < 2030; year++) {

        int doy = 0;
        int ileap = (int) ((year - 2020) % 4 == 0);

        for (int imonth = 0; imonth < NMONTHS; imonth++) {

            doy += MONTH_LENGTHS[ileap][imonth];

            split_date (doy, year, &month, &day);

            printf("doy %3d in %4d is %02d-%02d-%4d\n", doy, year, day + 1, month + 1, year);

        }

    }

    return 0;

}


void split_date (int day_of_year, int year, int *month, int *day) {

    int ndays = 0;

    int ileap = (int) ((year - 2020) % 4 == 0);

    for (int imonth = 0; imonth < NMONTHS; imonth++) {

        if (ndays < day_of_year) {
            *month = imonth;
            *day = day_of_year - 1 - ndays;
            ndays += MONTH_LENGTHS[ileap][imonth];
        }

    }

}
