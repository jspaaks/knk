#include <stdio.h>
typedef enum {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} Weekday;


int main (void) {
    Weekday today = WEDNESDAY;
    switch (today) {
        case MONDAY: {
            fprintf(stdout, "Today is Monday.\n");
            break;
        }
        case TUESDAY: {
            fprintf(stdout, "Today is Tuesday.\n");
            break;
        }
        case WEDNESDAY: {
            fprintf(stdout, "Today is Wednesday.\n");
            break;
        }
        case THURSDAY: {
            fprintf(stdout, "Today is Thursday.\n");
            break;
        }
        case FRIDAY: {
            fprintf(stdout, "Today is Friday.\n");
            break;
        }
        case SATURDAY: {
            fprintf(stdout, "Today is Saturday.\n");
            break;
        }
        case SUNDAY: {
            fprintf(stdout, "Today is Sunday.\n");
            break;
        }
        default: {
            fprintf(stderr, "Something went wrong.\n");
            return 1;
        }
    }
    return 0;
}
