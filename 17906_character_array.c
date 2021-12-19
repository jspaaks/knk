#include <stdio.h>
#include <ctype.h>

#define NCHARS_MAX 1000


int main (void) {

    printf("Enter message: ");

    char message[NCHARS_MAX];
    int nchars;

    for (int ichar = 0; ichar < NCHARS_MAX; ichar++) {

        char c = getchar();
        message[ichar] = c;
        nchars = ichar + 1;

        if (c == '\n') {
            break;
        }
    }

    printf("In B1FF-speak: ");
    for (int ichar = 0; ichar < nchars; ichar++) {

        char c = toupper(message[ichar]);

        switch (c) {
            case 'A':
                putchar('4');
                break;
            case 'B':
                putchar('8');
                break;
            case 'E':
                putchar('3');
                break;
            case 'I':
                putchar('1');
                break;
            case 'O':
                putchar('0');
                break;
            case 'S':
                putchar('5');
                break;
            case '\n':
                // postpone printing the newline until after the exclamation points
                break;
            default:
                putchar(c);
                break;
        }
    }

    // append exclamation points
    for (int i = 0, n = 10; i < n; i++) {
        putchar('!');
    }

    // now we can print the postponed newline
    putchar('\n');

    return 0;

}
