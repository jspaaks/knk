#include "quicksort.h"


int split (int a[], int ilow, int ihigh);


void quicksort (int a[], int ilow, int ihigh) {
    int imiddle;
    if (ilow >= ihigh) {
        return;
    }
    imiddle = split(a, ilow, ihigh);
    quicksort(a, ilow, imiddle - 1);
    quicksort(a, imiddle + 1, ihigh);
}



int split (int a[], int ilow, int ihigh) {

    int part_element = a[ilow];

    for (;;) {
        while (ilow < ihigh && part_element <= a[ihigh]) {
            ihigh--;
        }
        if (ilow >= ihigh) {
            break;
        }
        a[ilow] = a[ihigh];
        ilow++;


        while (ilow < ihigh && a[ilow] <= part_element) {
            ilow++;
        }
        if (ilow >= ihigh) {
            break;
        }
        a[ihigh] = a[ilow];
        ihigh--;

    }

    a[ihigh] = part_element;
    return ihigh;
}
