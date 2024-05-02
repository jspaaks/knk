#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int sum (int (*)(int), int, int);
int square (int);
int timestwo (int);

int sum (int (*g)(int), int start, int end) {
    assert(start <= end && "START should be less than or equal to END.");
    int i = start;
    int acc = 0;
    while (i <= end) {
        acc += (*g)(i);
        i++;
    }
    return acc;
}

int main (void) {
    int start = 2;
    int end = 5;
    fprintf(stdout, "sum of %s(i) for i=%d..%d = %d.\n", "timestwo", start, end, sum(timestwo, start, end));
    fprintf(stdout, "sum of %s(i) for i=%d..%d = %d.\n", "square", start, end, sum(square, start, end));
    return EXIT_SUCCESS;
}

int square (int i) {
    return i * i;
}

int timestwo (int i) {
    return i * 2;
}
