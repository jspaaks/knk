#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "time.h"
#include "flight.h"


Flight flights[8] = {
   {
      .dep = { .hours =  8, .minutes =  0 },
      .arr = { .hours = 10, .minutes = 16 }
   },
   {
      .dep = { .hours =  9, .minutes = 43 },
      .arr = { .hours = 11, .minutes = 52 }
   },
   {
      .dep = { .hours = 11, .minutes = 19 },
      .arr = { .hours = 13, .minutes = 31 }
   },
   {
      .dep = { .hours = 12, .minutes = 47 },
      .arr = { .hours = 15, .minutes =  0 }
   },
   {
      .dep = { .hours = 14, .minutes =  0 },
      .arr = { .hours = 16, .minutes =  8 }
   },
   {
      .dep = { .hours = 15, .minutes = 45 },
      .arr = { .hours = 17, .minutes = 55 }
   },
   {
      .dep = { .hours = 19, .minutes =  0 },
      .arr = { .hours = 21, .minutes = 20 }
   },
   {
      .dep = { .hours = 21, .minutes = 45 },
      .arr = { .hours = 23, .minutes = 58 }
   }
};


int nflights = sizeof flights / sizeof flights[0];


Time ask_user (void);
int find_closest(Time *);


Time ask_user (void){
   int hours;
   int minutes;
   printf("Enter a departure time in HH:mm format: ");
   scanf(" %d : %d", &hours, &minutes);
   Time t = new_time(hours, minutes);
   enrich_time_data(&t);
   return t;
}


int find_closest (Time * t) {
   bool better;
   int diff;
   int bestdiff;
   int r;
   for (int i = 0; i < nflights; i++) {
      diff = abs(flights[i].dep.mod - (*t).mod);
      better = diff < bestdiff;
      if (i == 0 || better) {
         bestdiff = diff;
         r = i;
      }
   }
   return r;
}


int main(void) {
   for (int i = 0; i < nflights; i++) {
      enrich_flight_data(&flights[i]);
   }
   Time t_requested = ask_user();
   int i = find_closest(&t_requested);
   fprintf(stdout, "Closest departure time is %s, arriving at %s.\n", flights[i].dep.ampm, flights[i].arr.ampm);
   return EXIT_SUCCESS;
}
