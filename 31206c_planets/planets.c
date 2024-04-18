#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NPLANETS 9

void adjust_input_capitalization(int n, char *strings[]) {
    for (int i = 0; i < n; i++) {
        char *c = strings[i];
        *c = toupper(*c);
        c++;
        while (*c != '\0') {
            *c = tolower(*c);
            c++;
        }
    }
}

int main(int nargs, char *argv[]) {

    adjust_input_capitalization(nargs, argv);

    char *planets[] = {"Mercury", "Venus", "Earth",
                       "Mars", "Jupiter", "Saturn",
                       "Uranus", "Neptune", "Pluto"};

    for (int iarg = 0; iarg < nargs; iarg++) {
        int iplanet;
        for (iplanet = 0; iplanet < NPLANETS; iplanet++) {
            char *planet = argv[iarg];
            if (strcmp(planet, planets[iplanet]) == 0) {
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
