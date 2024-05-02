#include <stdio.h>
#include <stdlib.h>

int f1 (int (*) (int));
int f2 (int);



int f1 (int (*f) (int)) {
    int n = 0;
    while ((*f)(n)) {
        n++;
    }
    return n;
}


int f2 (int i) {
    return i * i + i - 12;
}


int main (void) {
    fprintf(stdout, "Answer: %d\n", f1(f2));
    return EXIT_SUCCESS;
}
