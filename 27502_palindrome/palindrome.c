#include <stdio.h>
#include <ctype.h>

#define LEN 1000

void is_palindrome(char msg[], int nchars);

int main (void) {

    printf("Enter a message: ");
    int nchars = 0;
    char msg[LEN];
    for (int ichar = 0; ichar < LEN; ichar++) {
        char c = getchar();
        if (c == '\n') {
            break;
        } else {
            msg[ichar] = c;
            nchars++;
        }
    }
    is_palindrome(msg, nchars);
}


void is_palindrome(char msg[], int nchars) {
    char *p = &msg[0];
    char *q = &msg[nchars - 1];
    for (int i = 0; i < nchars; i++) {
        printf("i = %-2d *p = %c; *q = %c", i, *p, *q);
        if (!isalpha(*p)) {
            p++;
            printf(" - pass\n");
            continue;
        }
        if (!isalpha(*q)) {
            q--;
            printf(" - pass\n");
            continue;
        }
        printf(" - compare\n");
        if (tolower(*p) != tolower(*q)) {
            printf("Message is not a palindrome.\n");
            return;
        }
        p++;
        q--;
        if (p > q) {
            break;
        }
    }
    printf("Message is a palindrome.\n");
}
