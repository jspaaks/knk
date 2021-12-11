#include <stdio.h>

// dimensional weight factor for international shipping
#define DWEIGHT_FACTOR (166)

int main(void) {

    // shipping companies determine shipping fee based on one of two things:
    // (1) the actual weight
    // (2) the dimensional weight, calculated as the volume in cubic inches divided by 166

    int length, width, height, volume, volume_roundoff, dweight;

    printf("Enter the length of the first dimension in inches: ");
    scanf("%d", &length);
    printf("Enter the length of the second dimension in inches: ");
    scanf("%d", &width);
    printf("Enter the length of the third dimension in inches: ");
    scanf("%d", &height);

    volume = length * width * height;
    volume_roundoff = DWEIGHT_FACTOR - 1;
    dweight = (volume + volume_roundoff) / DWEIGHT_FACTOR;

    printf("dimensions\n");
    printf(" length : %5d %-8s\n", length, "[in]");
    printf(" width  : %5d %-8s\n", width, "[in]");
    printf(" height : %5d %-8s\n", height, "[in]");
    printf(" volume : %5d %-8s\n", volume, "[cu in]");
    printf(" dweight: %5d %-8s\n", dweight, "[lbs]");

}
