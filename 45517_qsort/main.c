#include <stdio.h>
#include <stdlib.h>

#define N 10

int comparator (const void *, const void *);
void print (int[]);

int comparator (const void * p, const void * q) {
    int * pp = (int *) p;
    int * qq = (int *) q;

    if (*pp < *qq) {
        return -1;
    } else if (*pp == *qq) {
        return 0;
    } else {
        return 1;
    }
}

int main (void) {
    int a[N] = { 462, 342, 3247, 25, 463, 44, 2456, 354, 6723, 451 };
    print(a);
    // e.g. sort only the entries on index 4..7
    qsort(a + 4, 4, sizeof(int), comparator);
    print(a);
}

void print (int a[]) {
    fprintf(stdout, "[ ");
    for (int i = 0; i < N; i++) {
        fprintf(stdout, "%d ", a[i]);
    }
    fprintf(stdout, "]\n");
}
