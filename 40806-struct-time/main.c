#include <stdio.h>
#define N 10

struct time {
    int hours;
    int minutes;
    int seconds;
};

struct time split_time(long);


int main (void) {
    long tests[N] = {0, 60, 3600, 3661, 21600, 43200, 64800, 86399, 86400, 360000 - 1};
    struct time t;
    for (int i = 0; i < N; i++) {
        t = split_time(tests[i]);
        printf("%9ld seconds equals %2d hours, %2d minutes and %2d seconds.\n", tests[i], t.hours, t.minutes, t.seconds);
    }
    return 0;
}


struct time split_time(long total_seconds) {
    const long SECONDS_PER_HOUR = 60 * 60;
    const int SECONDS_PER_MINUTE = 60;

    long remaining;
    int hours;
    int minutes;
    int seconds;

    remaining = total_seconds;
    hours = remaining / SECONDS_PER_HOUR;
    remaining -= hours * SECONDS_PER_HOUR;
    minutes = remaining / SECONDS_PER_MINUTE;
    remaining -= minutes * SECONDS_PER_MINUTE;
    seconds = remaining;
    struct time t = {hours, minutes, seconds};

    return t;
}
