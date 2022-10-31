#include <stdio.h>

void make_identity_using_subscripts(int n, int[n][n]);
void make_identity_using_pointers(int n, int[n][n]);
void print_2d_array(int n, int[n][n]);

int main (void) {

    int n = 5;
    int a[n][n];
    int b[n][n];

    make_identity_using_subscripts(n, a);
    print_2d_array(n, a);

    make_identity_using_pointers(n, b);
    print_2d_array(n, b);
}

void make_identity_using_subscripts(int n, int a[n][n]) {
    for (int i = 0; i < n; i++) {
        a[i][i] = 1;
    }
    return;
}

void make_identity_using_pointers(int n, int a[n][n]) {
    for (int *i = &a[0][0]; i < &a[n][n]; i+= n + 1) {
        *i = 1;
    }
    return;
}

void print_2d_array(int n, int a[n][n]) {
    printf("{\n");
    for (int irow = 0; irow < n; irow++) {
        printf("   {");
        for (int icol = 0; icol < n - 1; icol++) {
            printf("%d, ", a[irow][icol]);
        }
        printf("%d}\n", a[irow][n - 1]);
    }
    printf("}\n");
    return;
}
