#include <stdio.h>

// dimensional weight factor for international shipping
#define DWEIGHT_FACTOR (166)

int main(void) {

    // shipping companies determine shipping fee based on one of two things:
    // (1) the actual weight
    // (2) the dimensional weight, calculated as the volume in cubic inches divided by 166
    //

    int length = 12;
    int width = 10;
    int height = 8;
    int volume = length * width * height;
    int volume_roundoff = DWEIGHT_FACTOR - 1;
    int dweight = (volume + volume_roundoff) / DWEIGHT_FACTOR;

    printf("dimensions\n");
    printf(" length : %5d %-8s\n", length, "[in]");
    printf(" width  : %5d %-8s\n", width, "[in]");
    printf(" height : %5d %-8s\n", height, "[in]");
    printf(" volume : %5d %-8s\n", volume, "[cu in]");
    printf(" dweight: %5d %-8s\n", dweight, "[lbs]");

}
