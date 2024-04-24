#include <stdio.h>

void swap (int *p, int *q);

int main (void) {

    int i = 9;
    int j = 10;

    int *i_ptr = &i;
    int *j_ptr = &j;

    printf("i = %2d @ %p\n", i, i_ptr);
    printf("j = %2d @ %p\n", j, j_ptr);

    swap(i_ptr, j_ptr);

    printf("i = %2d @ %p\n", i, i_ptr);
    printf("j = %2d @ %p\n", j, j_ptr);

    return 0;

}


void swap (int *p, int *q) {

    int tmp = *p;
    *p = *q;
    *q = tmp;

}
