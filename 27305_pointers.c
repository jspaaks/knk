#include <stdio.h>

int main (void) {

    int a[] = {1, 2, 3, 4};
    int *p;

    p = a;

    printf("invalid comparison: p == a[0] = %d\n", p == a[0]);
    printf("  valid comparison: p == &a[0] = %d\n", p == &a[0]);
    printf("  valid comparison: *p == a[0] = %d\n", *p == a[0]);
    printf("  valid comparison: p[0] == a[0] = %d\n", p[0] == a[0]);

}
