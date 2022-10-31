#include <stdbool.h>
#include <stdio.h>

#define NROWS 3
#define NCOLS 24

bool search(const int[], int, int);
void print_temps(int[], int);
int *find_largest(int [], int);

int main (void) {
    int temperatures[NROWS][NCOLS] = {
        {  0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20,  21,  22,  23},
        { 24,  25,  26,  27,  28,  29,  30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47},
        { 48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  62,  63,  64,  65,  66,  67,  68,  69,  70,  71}
    };

    bool has32 = search(temperatures[0], NROWS * NCOLS, 32); // antipattern but ok
    printf("has 32: %s\n", has32 ? "true" : "false");

    for (int irow = 0; irow < NROWS; irow++) {
        print_temps(temperatures[irow], NCOLS);
        printf("| max: %d", *find_largest(temperatures[irow], NCOLS));
        printf("\n");
    }
}

bool search(const int a[], int n, int key) {
    for (const int *i = &a[0]; i < &a[n]; i++) {
        if (key == *i) {
            return true;
        }
    }
    return false;
}


void print_temps(int a[], int n) {
    for (int *i = &a[0]; i < &a[n - 1]; i++) {
        printf("% 3d, ", *i);
    }
    printf("% 3d", a[n - 1]);
    return;
}

int *find_largest(int a[], int n) {

    int *this = &a[0];
    int *largest = &a[0];

    for (int i = 0; i < n; i++) {
        if (*this > *largest) {
            largest = this;
        }
        this++;
    }
    return largest;
}

