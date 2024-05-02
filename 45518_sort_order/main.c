#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef int (*CompFun)(const void *, const void *);

CompFun comparator (bool);
int comparator_asc (const void *, const void *);
int comparator_desc (const void *, const void *);
void print (int[]);

CompFun comparator (bool is_asc) {
    return is_asc == true ? comparator_asc : comparator_desc;
}

int comparator_asc (const void * p, const void * q) {
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

int comparator_desc (const void * p, const void * q) {
    int * pp = (int *) p;
    int * qq = (int *) q;

    if (*pp > *qq) {
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
    bool is_asc = false;
    qsort(a, N, sizeof(int), comparator(is_asc));
    print(a);
}

void print (int a[]) {
    fprintf(stdout, "[ ");
    for (int i = 0; i < N; i++) {
        fprintf(stdout, "%d ", a[i]);
    }
    fprintf(stdout, "]\n");
}
