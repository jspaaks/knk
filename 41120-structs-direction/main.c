#include <stdio.h>
#include <string.h>


int main (void) {
    int x = 0;
    int y = 0;
    enum { NORTH = 0, SOUTH = 180, EAST = 90, WEST = 270 } direction = WEST;
    char direction_str[6] = { '\0' };

    switch (direction) {
        case NORTH: {
            strncpy(direction_str, "North", 6);
            y++;
            break;
        }
        case SOUTH: {
            strncpy(direction_str, "South", 6);
            y--;
            break;
        }
        case EAST: {
            strncpy(direction_str, "East", 5);
            x++;
            break;
        }
        case WEST: {
            strncpy(direction_str, "West", 5);
            x--;
            break;
        }
        default: {
            fprintf(stderr, "Something went wrong.\n");
            return 1;
        }
    }
    fprintf(stdout, "direction: %3d (%s)\n", direction, direction_str);
    fprintf(stdout, "        x: %3d\n", x);
    fprintf(stdout, "        y: %3d\n", y);
    return 0;
}
