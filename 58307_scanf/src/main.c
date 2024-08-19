#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int i;
    int j;
    int n;
    float x;
    n = scanf("%d%f%d", &i, &x, &j);
    
    fprintf(stdout, "i = %d, x = %f, j = %d; read %d elements.\n", i, x, j, n);

    return EXIT_SUCCESS;
}
