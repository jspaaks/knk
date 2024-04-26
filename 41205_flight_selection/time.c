#include <stdio.h>
#include <string.h>
#include "time.h"


void derive_ampm (Time *);
void derive_military (Time *);
void derive_mod (Time *);


void derive_ampm (Time * t) {
    int hours24 = (*t).hours;
    int hours12 = hours24 % 12;
    sprintf((*t).ampm, "%d:%02d %cm", hours12 == 0 ? 12 : hours12, (*t).minutes, hours24 < 12 ? 'a' : 'p');
}


void derive_military (Time * t) {
    sprintf((*t).military, "%2d:%02d", (*t).hours, (*t).minutes);
}


void derive_mod(Time * t) {
    (*t).mod = (*t).hours * 60 + (*t).minutes;
}

void enrich_time_data(Time * t) {
    derive_ampm(t);
    derive_military(t);
    derive_mod(t);
}


Time new_time(int hours, int minutes) {
    Time t;
    t.hours = hours;
    t.minutes = minutes;
    return t;
}
