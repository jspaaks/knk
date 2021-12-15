#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>


int main (void) {

    printf("Enter a first and last name separated by a space: ");

    char c_prev = ' ';
    char c;
    int iname = -1;
    char initial;
    int n_trailing_spaces = 0;


    while (true) {

        c = getchar();

        if (c == '\n') {
            for (int i = 0; i < n_trailing_spaces; i++) {
                putchar('\b');
            }
            break;
        }

        if (c_prev == ' ' && c != ' ') {
            iname += 1;
            n_trailing_spaces = 0;
            if (iname == 0) {
                initial = c;
            }
        }

        if (iname > 0) {
            if (c_prev == ' ' && c == ' ') {
                continue;
            } else {
                putchar(c);
            }
            if (c == ' ') {
                n_trailing_spaces += 1;
            }
        }

        c_prev = c;

    }

    printf(", %1c.\n", initial);

    return 0;

}

