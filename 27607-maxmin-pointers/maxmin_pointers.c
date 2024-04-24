#include <stdio.h>

#define N 10

void max_min(int *first, int *last, int *max, int *min);

int main(void) {
    int b[N];
    int big;
    int small;

    printf("Enter %d numbers: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &b[i]);
    }

    max_min(&b[0], &b[N - 1], &big, &small);

    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);

    return 0;
}

void max_min(int* first, int *last, int *max, int *min) {
    *max = *min = *first;
    for (int *p = first; p <= last; p++) {
        if (*p > *max) {
            *max = *p;
        } else if (*p < *min) {
            *min = *p;
        }
    }
}
