#define IS_MAIN

#include <stdio.h>
#include "globals.h"
#include "increment.h"
#include "decrement.h"


int main (void) {
   printf("%d\n", v);
   increment(3);
   printf("%d\n", v);
   decrement(10);
   printf("%d\n", v);
}
