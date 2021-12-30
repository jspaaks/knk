#include <stdio.h>

void calc_avg_sum(const double a[], int n, double *avg, double *sum);


void calc_avg_sum(const double a[], int n, double *avg, double *sum) {

    *sum = 0.0;

    for (int i = 0; i < n; i++) {
        *sum += a[i];
    }

    *avg = *sum / n;

    return;

}


int main (void) {

    double a[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int n = (int) (sizeof(a) / sizeof(a[0]));
    double avg = 0.0;
    double sum = 0.0;

    calc_avg_sum(a, n, &avg, &sum);

    printf("sum = %.4lf\n", sum);
    printf("avg = %.4lf\n", avg);

    return 0;

}
