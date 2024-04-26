#ifndef TIME_H
#define TIME_H

#include <stdbool.h>

typedef struct {
    int hours;
    int minutes;
    int mod;
    char ampm[9];
    char military[6];
} Time;


typedef enum { AMPM, MILITARY } TimeFormat;

void enrich_time_data(Time *);
Time new_time(int, int);

#endif
