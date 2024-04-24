#include <stdio.h>

int *find_middle(int[], int n);

int main (void) {

    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof a / sizeof a[0];
    int *p = find_middle(&a[0], n);
    printf("middle element is: %d\n", *p);
}

int *find_middle(int a[], int n) {
    return a + n / 2;
}
