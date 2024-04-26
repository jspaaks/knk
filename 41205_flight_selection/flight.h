#ifndef FLIGHT_H
#define FLIGHT_H

#include "time.h"

typedef struct {
    Time arr;
    Time dep;
} Flight;


void enrich_flight_data(Flight *);

#endif
