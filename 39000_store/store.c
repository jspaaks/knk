#include <stdio.h>
#include "types.h"

Part p = {.num = 5, .s = "boing"};


void print_store (void) {
    printf("store {\n  .num: %d\n  .s  : \"%s\"\n}\n", p.num, p.s);
}
