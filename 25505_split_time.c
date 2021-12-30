#include <stdio.h>

void split_time(long total_sec, int *hr, int *min, int *sec);


int main (void) {

    long duration = 7322L;

    int hours;
    int minutes;
    int seconds;

    split_time(duration, &hours, &minutes, &seconds);

    printf("%d hours, %d minutes, and %d seconds amounts to a total of %ld seconds.\n", hours, minutes, seconds, duration);

    return 0;

}


void split_time(long total_sec, int *hr, int *min, int *sec) {

    const int SECONDS_PER_HOUR = 3600;
    const int SECONDS_PER_MINUTE = 60;

    long remaining = total_sec;

    *hr = (int) (remaining / SECONDS_PER_HOUR);

    remaining = remaining - *hr * SECONDS_PER_HOUR;

    *min = (int) (remaining / SECONDS_PER_MINUTE);

    remaining = remaining - *min * SECONDS_PER_MINUTE;

    *sec = (int) remaining;

    return;

}
