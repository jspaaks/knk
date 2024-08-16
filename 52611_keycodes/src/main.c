#include <stdio.h>
#include <stdlib.h>

#define SHIFT_BIT 1
#define CTRL_BIT 2
#define ALT_BIT 4

int main (void) {
    int keycode = 8;
    if ((keycode & (SHIFT_BIT | CTRL_BIT | ALT_BIT)) == 0) {
        fprintf(stdout, "No modifiers pressed.\n");
    } else {
        fprintf(stdout, "Modifier pressed.\n");
    }

    return EXIT_SUCCESS;
}
