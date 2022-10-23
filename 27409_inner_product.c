#include <stdio.h>

double inner_product_subscripts(const double *, const double *, int);
double inner_product_pointers(const double *, const double *, int);

int main (void) {

    double a[] = {1.0, 2.0 , 3.0};
    double b[] = {2.0, 3.0 , 4.0};
    int n = sizeof a / sizeof a[0];

    printf("a = {");
    for (int i = 0; i < n - 1; i++) {
        printf("%f, ", a[i]);
    }
    printf("%f}\n", a[n - 1]);

    printf("b = {");
    for (int i = 0; i < n - 1; i++) {
        printf("%f, ", b[i]);
    }
    printf("%f}\n", b[n - 1]);

    printf("inner product (subscripts) = %f\n", inner_product_subscripts(a, b, n));
    printf("inner product (pointers) = %f\n", inner_product_pointers(a, b, n));
}

double inner_product_subscripts(const double *a, const double *b, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}


double inner_product_pointers(const double *a, const double *b, int n) {
    double sum = 0.0;
    const double *ai = &a[0];
    const double *bi = &b[0];
    for (int i = 0; i < n; i++) {
        sum += *ai * *bi;
        ai++;
        bi++;
    }
    return sum;
}
