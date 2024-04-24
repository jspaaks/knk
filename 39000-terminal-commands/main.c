#include <stdio.h>
#include <stdbool.h>
#include "ansicmds.h"


void show_screen_create_part (void);



int main (void) {
    setbuf(stdout, NULL);
    show_screen_create_part();
    while (true) {
        ;
    }
}


void show_screen_create_part (void) {
    clear_screen();
    move_cursor_to_pos(1, 1);
    printf("Enter part number:");

    move_cursor_to_pos(2, 1);
    printf("Enter part name  :");

    move_cursor_to_pos(1, 20);
}
