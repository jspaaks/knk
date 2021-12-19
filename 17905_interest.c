#include <stdio.h>


#define INITIAL_BALANCE 100.00

int main (void) {

    double low_rate;

    printf("Enter monthly interest rate: ");
    scanf("%lf", &low_rate);

    int nyears;

    printf("Enter number of years: ");
    scanf("%d", &nyears);

    printf("\n");
    printf("        Investment value after n years\n");
    printf("\n");
    printf("       ");

    double value[5];
    int nrates = (int) (sizeof(value) / sizeof(value[0]));

    for (int irate = 0; irate < nrates; irate++) {
        printf("%6.2f%% ", low_rate + irate);
        value[irate] = INITIAL_BALANCE;
    }

    printf("\n");
    printf("Years\n");

    int nmonths = 12 * nyears;

    for (int imonth = 1; imonth <= nmonths; imonth++) {

        for (int irate = 0; irate < nrates; irate++) {

            value[irate] += (low_rate + irate) / 100.0 * value[irate];

            if (imonth % 12 == 0) {
                if (irate == 0) {
                    printf("%3d    ", imonth / 12);
                }
                printf("%6.2f  ", value[irate]);
                if (irate == nrates - 1) {
                    printf("\n");
                }
            }
        }
    }

    return 0;

}

// Numbers should match the original example when you express the percentage as a growth factor,
// then raise that to the (1/12) power, e.g 6% yearly is the same as 0.48% monthly
