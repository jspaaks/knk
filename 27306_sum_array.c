#include <stdio.h>

int sum_array_via_indexing(const int[], int);
int sum_array_via_pointers(const int[], int);

int main (void) {
    int a[] = {2, 4, 6, 8};
    int n = sizeof a / sizeof a[0];
    printf("{");
    for (int i = 0; i < n - 1; i++) {
        printf("%d, ", a[i]);
    }
    printf("%d}\n", a[n - 1]);
    printf("summing via indexing: %d\n", sum_array_via_indexing(a, n));
    printf("summing via pointers: %d\n", sum_array_via_pointers(a, n));
}

int sum_array_via_indexing(const int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

int sum_array_via_pointers(const int a[], int n) {
    int sum = 0;
    for (const int *i = &a[0]; i < &a[n]; i++) {
        // `const int *i` does not make `i` a constant, just `*i`
        // `int * const i` would make the pointer itself constant.
        sum += *i;
    }
    return sum;
}
