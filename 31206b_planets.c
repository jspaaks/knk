#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NPLANETS 9

int main(int nargs, char *argv[]) {

    char *planets[] = {"Mercury", "Venus", "Earth",
                       "Mars", "Jupiter", "Saturn",
                       "Uranus", "Neptune", "Pluto"};

    for (int iarg = 0; iarg < nargs; iarg++) {
        int iplanet;
        for (iplanet = 0; iplanet < NPLANETS; iplanet++) {
            if (strcmp(argv[iarg], planets[iplanet]) == 0) {
                printf("%s is planet %d\n", planets[iplanet], iplanet + 1);
                break;
            }
        }
        if (iplanet == NPLANETS) {
            printf("%s is not a planet\n", argv[iarg]);
        }
    }
    return EXIT_SUCCESS;
}
