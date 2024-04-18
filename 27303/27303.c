#include <stdio.h>

#define N 10

void print_arr(int *);



int main (void) {

    int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = &a[0], *q = &a[N - 1], temp;

    print_arr(&a[0]);

    while (p < q) {
        temp = *p;
        *p++ = *q;
        *q-- = temp;
    }

    print_arr(&a[0]);
    return 0;

}


void print_arr(int *arr) {
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
