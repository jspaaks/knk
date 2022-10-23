#include <stdbool.h>
#include <stdio.h>

bool search(const int a[], int n, int key);


int main (void) {
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof a / sizeof a[0];

    for (int i = -1; i < 8; i++) {
        printf("{");
        for (int i = 0; i < n - 1; i++) {
            printf("%d, ", a[i]);
        }
        printf("%d}", a[n - 1]);
        printf(" contains % 2d: %s\n", i, search(a, n, i) ? "true" : "false");
    }
}

bool search(const int a[], int n, int key) {
    for (const int *i = &a[0]; i < &a[n]; i++) {
        if (key == *i) {
            return true;
        }
    }
    return false;
}
