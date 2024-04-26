#ifndef DATES_H
#define DATES_H

typedef struct {
    int day;
    int month;
    int year;
} Date;


int compare_dates(Date, Date);
int day_of_year (Date);

#endif
