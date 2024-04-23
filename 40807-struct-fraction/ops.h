#ifndef OPS_H
#define OPS_H

#include "fraction.h"

struct fraction add (struct fraction, struct fraction);
struct fraction create(int, int);
struct fraction divide (struct fraction, struct fraction);
struct fraction multiply (struct fraction, struct fraction);
struct fraction reduce (struct fraction);
struct fraction subtract (struct fraction, struct fraction);

#endif
