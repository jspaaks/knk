#include "time.h"
#include "flight.h"


void enrich_flight_data(Flight * flight) {
    enrich_time_data(&(*flight).dep);
    enrich_time_data(&(*flight).arr);
}
