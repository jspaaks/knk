#include <stdio.h>
#include <stdbool.h>


void selection_sort(int arr[], int n);


int main (void) {

    printf("How many elements will your array have: ");
    int n;
    scanf("%d", &n);

    printf("Enter a series of %d integers: ", n);

    int numbers[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    selection_sort(numbers, n);


    // print the numbers
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;

}


void selection_sort(int a[], int n) {

    int largest = a[0];
    int ilargest = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > largest) {
            largest = a[i];
            ilargest = i;
        }
    }
    // let largest value and last value switch positions
    int tmp = a[n - 1];
    a[n - 1] = largest;
    a[ilargest] = tmp;

    // recursive call
    if (n > 2) {
        selection_sort(a, n - 1);
    }

}
