#include <stdio.h>

void testfun0 (int i, int *j);
void testfun1 (int a[], int n);
void testfun2 (int a[], int n);
void testfun3 (int *a, int n);
void testfun4 (int *a, int n);



int main (void) {

    int i = 2;
    int j = 5;
    int arr[] = {13, 41};
    int n = (int) (sizeof(arr) / sizeof(arr[0]));

    int *p;
    p = &i;

    printf("main    : i        = %d\n          j        = %d\n", i, j);
    testfun0(i, &j);
    printf("main    : i        = %d\n          j        = %d\n", i, j);
    printf("main    : p        = %p\n", p);
    printf("main    : *p       = %d\n", *p);
    printf("main    : p[0]     = %d\n", p[0]);
    printf("main    : *(p + 0) = %d\n", *(p + 0));
    printf("main    : &arr     = %p\n", &arr);
    printf("main    : arr      = %p\n", arr);
    printf("main    : &arr[0]  = %p\n", &arr[0]);

    printf("\n");

    testfun1(arr, n);
    printf("\n");

    testfun2(&arr[0], n);
    printf("\n");

    testfun3(arr, n);
    printf("\n");

    testfun4(&arr[0], n);
    printf("\n");

    return 0;

}


void testfun0 (int i, int *j) {

    i = i + 1;
    *j = *j + 1;

    printf("testfun0: i        = %d\n          *j       = %d\n", i, *j);

    return;

}


void testfun1 (int a[], int n) {

    printf("testfun1: &a       = %p\n", &a);
    printf("testfun1: a        = %p\n", a);
    printf("testfun1: &a[0]    = %p\n", &a[0]);

    for (int i = 0; i < n; i++) {
        printf("testfun1: a[%d]     = %d\n", i, a[i]);
    }

    return;

}


void testfun2 (int a[], int n) {

    printf("testfun2: &a       = %p\n", &a);
    printf("testfun2: a        = %p\n", a);
    printf("testfun2: &a[0]    = %p\n", &a[0]);

    for (int i = 0; i < n; i++) {
        printf("testfun2: *(a + %d) = %d\n", i, *(a + i));
    }

    return;

}


void testfun3 (int *a, int n) {

    printf("testfun3: &a       = %p\n", &a);
    printf("testfun3: a        = %p\n", a);
    printf("testfun3: &a[0]    = %p\n", &a[0]);

    for (int i = 0; i < n; i++) {
        printf("testfun3: a[%d]     = %d\n", i, a[i]);
    }

    return;

}


void testfun4 (int *a, int n) {

    printf("testfun4: &a       = %p\n", &a);
    printf("testfun4: a        = %p\n", a);
    printf("testfun4: &a[0]    = %p\n", &a[0]);

    for (int i = 0; i < n; i++) {
        printf("testfun4: *(a + %d) = %d\n", i, *(a + i));
    }

    return;

}
