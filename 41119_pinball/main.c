#include <stdio.h>


struct pinball_machine {
    char name[40];
    int year;
    enum {EM, SS} type;
    int players;
};

int main (void) {
    struct pinball_machine m = {
        .name = "Rage against the Machine",
        .year = 1998,
        .type = EM,
        .players = 2
    };
    char fmt[] = "name   : %s\nyear   : %d\ntype   : %s\nplayers: %d\n";
    fprintf(stdout, fmt, m.name, m.year, m.type == EM ? "EM" : "SS", m.players);
}
