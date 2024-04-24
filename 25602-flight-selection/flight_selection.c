#include <stdio.h>

void find_closest_flight (int desired_time, int *departure_time, int *arrival_time);


void find_closest_flight (int desired_time, int *departure_time, int *arrival_time) {

    int diff_best = 24 * 60;
    int diff;

    int dep0 =  8 * 60 + 0;
    int arr0 = 10 * 60 + 16;
    diff = desired_time < dep0 ? dep0 - desired_time : desired_time - dep0;
    if (diff < diff_best) {
       *departure_time = dep0;
       *arrival_time = arr0;
       diff_best = diff;
    }

    int dep1 =  9 * 60 + 43;
    int arr1 = 11 * 60 + 52;
    diff = desired_time < dep1 ? dep1 - desired_time : desired_time - dep1;
    if (diff < diff_best) {
       *departure_time = dep1;
       *arrival_time = arr1;
       diff_best = diff;
    }

    int dep2 = 11 * 60 + 19;
    int arr2 = 13 * 60 + 31;
    diff = desired_time < dep2 ? dep2 - desired_time : desired_time - dep2;
    if (diff < diff_best) {
       *departure_time = dep2;
       *arrival_time = arr2;
       diff_best = diff;
    }

    int dep3 = 12 * 60 + 47;
    int arr3 = 15 * 60 + 0;
    diff = desired_time < dep3 ? dep3 - desired_time : desired_time - dep3;
    if (diff < diff_best) {
       *departure_time = dep3;
       *arrival_time = arr3;
       diff_best = diff;
    }

    int dep4 = 14 * 60 + 0;
    int arr4 = 16 * 60 + 8;
    diff = desired_time < dep4 ? dep4 - desired_time : desired_time - dep4;
    if (diff < diff_best) {
       *departure_time = dep4;
       *arrival_time = arr4;
       diff_best = diff;
    }

    int dep5 = 15 * 60 + 45;
    int arr5 = 17 * 60 + 55;
    diff = desired_time < dep5 ? dep5 - desired_time : desired_time - dep5;
    if (diff < diff_best) {
       *departure_time = dep5;
       *arrival_time = arr5;
       diff_best = diff;
    }

    int dep6 = 19 * 60 + 0;
    int arr6 = 21 * 60 + 20;
    diff = desired_time < dep6 ? dep6 - desired_time : desired_time - dep6;
    if (diff < diff_best) {
       *departure_time = dep6;
       *arrival_time = arr6;
       diff_best = diff;
    }

    int dep7 = 21 * 60 + 45;
    int arr7 = 23 * 60 + 58;
    diff = desired_time < dep7 ? dep7 - desired_time : desired_time - dep7;
    if (diff < diff_best) {
       *departure_time = dep7;
       *arrival_time = arr7;
       diff_best = diff;
    }

    return;
}


int main (void) {


    // program doesn't take into account closest departure times the next day or the previous day

    int hh24;
    int mm;

    printf("Enter a departure time in 24-hour format: ");
    scanf(" %d : %d", &hh24, &mm);

    int dep_user = hh24 * 60 + mm;

    int dep;
    int arr;

    find_closest_flight(dep_user, &dep, &arr);

    int dep_hh24 = dep / 60;
    int dep_mm = dep % 60;
    char dep_hh12 = dep_hh24 % 12;
    if (dep_hh12 == 0) {
        dep_hh12 = 12;
    }
    char dep_am_pm = dep_hh24 >= 12 ? 'P' : 'A';

    int arr_hh24 = arr / 60;
    int arr_mm = arr % 60;
    char arr_hh12 = arr_hh24 % 12;
    if (arr_hh12 == 0) {
        arr_hh12 = 12;
    }
    char arr_am_pm = arr_hh24 >= 12 ? 'P' : 'A';

    printf("Requested time of departure: %02d:%02d\n", dep_user / 60, dep_user % 60);
    printf("Closest departure time is %02d:%02d %1cM, arriving at %02d:%02d %1cM\n",
            dep_hh12, dep_mm, dep_am_pm,
            arr_hh12, arr_mm, arr_am_pm);

    return 0;

}
