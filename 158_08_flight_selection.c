#include <stdio.h>
#include <stdbool.h>


int main (void) {


    // program doesn't take into account closest departure times the next day or the previous day

    int hh12;
    int mm;

    printf("Enter a departure time in 12-hour format: ");
    scanf(" %d : %d", &hh12, &mm);

    char c;
    int hh24;

    while (true) {
        c = getchar();
        if (c == '\n') {
            break;
        } else if (c == ' ') {
            continue;
        } else if (c == 'a' || c == 'A') {
            if (hh12 == 12) {
                hh24 = 0;
            } else {
                hh24 = hh12;
            }
            break;
        } else if (c == 'p' || c == 'P') {
            if (hh12 == 12) {
                hh24 = 12;
            } else {
                hh24 = (12 + hh12) % 24;
            }
            break;
        } else {
            printf("Invalid input, aborting.\n");
            return 1;
        }
    }

    int dep_user = hh24 * 60 + mm;
    int diff_best = 24 * 60;
    int dep_best;
    int arr_best;
    int diff;

    int dep0 =  8 * 60 + 0;
    int arr0 = 10 * 60 + 16;
    diff = dep_user < dep0 ? dep0 - dep_user : dep_user - dep0;
    if (diff < diff_best) {
       dep_best = dep0;
       arr_best = arr0;
       diff_best = diff;
    }

    int dep1 =  9 * 60 + 43;
    int arr1 = 11 * 60 + 52;
    diff = dep_user < dep1 ? dep1 - dep_user : dep_user - dep1;
    if (diff < diff_best) {
       dep_best = dep1;
       arr_best = arr1;
       diff_best = diff;
    }

    int dep2 = 11 * 60 + 19;
    int arr2 = 13 * 60 + 31;
    diff = dep_user < dep2 ? dep2 - dep_user : dep_user - dep2;
    if (diff < diff_best) {
       dep_best = dep2;
       arr_best = arr2;
       diff_best = diff;
    }

    int dep3 = 12 * 60 + 47;
    int arr3 = 15 * 60 + 0;
    diff = dep_user < dep3 ? dep3 - dep_user : dep_user - dep3;
    if (diff < diff_best) {
       dep_best = dep3;
       arr_best = arr3;
       diff_best = diff;
    }

    int dep4 = 14 * 60 + 0;
    int arr4 = 16 * 60 + 8;
    diff = dep_user < dep4 ? dep4 - dep_user : dep_user - dep4;
    if (diff < diff_best) {
       dep_best = dep4;
       arr_best = arr4;
       diff_best = diff;
    }

    int dep5 = 15 * 60 + 45;
    int arr5 = 17 * 60 + 55;
    diff = dep_user < dep5 ? dep5 - dep_user : dep_user - dep5;
    if (diff < diff_best) {
       dep_best = dep5;
       arr_best = arr5;
       diff_best = diff;
    }

    int dep6 = 19 * 60 + 0;
    int arr6 = 21 * 60 + 20;
    diff = dep_user < dep6 ? dep6 - dep_user : dep_user - dep6;
    if (diff < diff_best) {
       dep_best = dep6;
       arr_best = arr6;
       diff_best = diff;
    }

    int dep7 = 21 * 60 + 45;
    int arr7 = 23 * 60 + 58;
    diff = dep_user < dep7 ? dep7 - dep_user : dep_user - dep7;
    if (diff < diff_best) {
       dep_best = dep7;
       arr_best = arr7;
       diff_best = diff;
    }

    int dep_best_hh24 = dep_best / 60;
    int dep_best_mm = dep_best % 60;
    char dep_best_hh12 = dep_best_hh24 % 12;
    if (dep_best_hh12 == 0) {
        dep_best_hh12 = 12;
    }
    char dep_best_am_pm = dep_best_hh24 >= 12 ? 'P' : 'A';

    int arr_best_hh24 = arr_best / 60;
    int arr_best_mm = arr_best % 60;
    char arr_best_hh12 = arr_best_hh24 % 12;
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
