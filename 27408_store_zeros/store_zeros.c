#include <stdio.h>

void store_zeros_using_subscripts(int[], int);
void store_zeros_using_pointers(int[], int);
void print_array(int[], int);

int main (void){

    int n = 4;
    int a[] = {1, 2, 3, 4};
    int b[] = {5, 6, 7, 8};

    printf("a (before) = ");
    print_array(a, n);

    store_zeros_using_subscripts(a, n);

    printf("a (after)  = ");
    print_array(a, n);

    printf("b (before) = ");
    print_array(b, n);

    store_zeros_using_pointers(b, n);

    printf("b (after)  = ");
    print_array(b, n);

}


void store_zeros_using_subscripts(int a[], int n){
    int i;
    for (i = 0; i < n; i++){
        a[i] = 0;
    }
}

void store_zeros_using_pointers(int a[], int n){
    int *i;
    for (i = &a[0]; i < &a[n]; i++){
        *i = 0;
    }
}

void print_array(int a[], int n) {
    printf("{");
    for (int i = 0; i < n - 1; i++) {
        printf("%d, ", a[i]);
    }
    printf("%d}\n", a[n - 1]);
}
