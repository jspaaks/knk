#include <stdio.h>


int main (void) {
    printf("program\n");

    struct {
        int x;
        int y;
    } x;
    struct {
        int x;
        int y;
    } y;

    x.x = 4;
    x.y = 5;

    y.x = 6;
    y.y = 7;

    printf("x.x = %d\nx.y = %d\ny.x = %d\ny.y = %d\n", x.x, x.y, y.x, y.y);

}
