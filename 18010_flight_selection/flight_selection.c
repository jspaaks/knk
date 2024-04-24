#include <stdio.h>
#include <math.h>


int main (void) {


    // program doesn't take into account closest departure times the next day or the previous day

    int hh24;
    int mm;

    printf("Enter a departure time in 24-hour format: ");
    scanf(" %d : %d", &hh24, &mm);

    int dep_user = hh24 * 60 + mm;
    int diff_best = 24 * 60;
    int dep_best;
    int arr_best;
    int diff;

    int departures[8] = {
         8 * 60 +  0,
         9 * 60 + 43,
        11 * 60 + 19,
        12 * 60 + 47,
        14 * 60 +  0,
        15 * 60 + 45,
        19 * 60 +  0,
        21 * 60 + 45
    };

    int arrivals[8] = {
        10 * 60 + 16,
        11 * 60 + 52,
        13 * 60 + 31,
        15 * 60 +  0,
        16 * 60 +  8,
        17 * 60 + 55,
        21 * 60 + 20,
        23 * 60 + 58
    };

    int nflights = (int) (sizeof(departures) / sizeof(departures[0]));

    for (int iflight = 0; iflight < nflights; iflight++) {

        diff = fabs((double) (dep_user - departures[iflight]));

        if (diff < diff_best) {
           dep_best = departures[iflight];
           arr_best = arrivals[iflight];
           diff_best = diff;
        }
    }

    int dep_best_hh24 = dep_best / 60;
    int dep_best_mm = dep_best % 60;
    int dep_best_hh12 = dep_best_hh24 % 12;
    if (dep_best_hh12 == 0) {
        dep_best_hh12 = 12;
    }
    char dep_best_am_pm = dep_best_hh24 >= 12 ? 'P' : 'A';

    int arr_best_hh24 = arr_best / 60;
    int arr_best_mm = arr_best % 60;
    int arr_best_hh12 = arr_best_hh24 % 12;
    if (arr_best_hh12 == 0) {
        arr_best_hh12 = 12;
    }
    char arr_best_am_pm = arr_best_hh24 >= 12 ? 'P' : 'A';

    printf("Requested time of departure: %02d:%02d\n", dep_user / 60, dep_user % 60);
    printf("Closest departure time is %02d:%02d %1cM, arriving at %02d:%02d %1cM\n",
            dep_best_hh12, dep_best_mm, dep_best_am_pm,
            arr_best_hh12, arr_best_mm, arr_best_am_pm);

    return 0;

}
