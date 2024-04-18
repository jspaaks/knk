#include <stdio.h>
#include <ctype.h>

#define NCHARS 1000

void is_palindrome(char *);
void read(char *);


void is_palindrome(char *msg) {
    char *p = msg;
    char *q = msg;
    while (*q != '\0') {
        q++;
    }
    q--;
    while (p < q) {
        printf("*p = %c; *q = %c", *p, *q);
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
    }
    printf("Message is a palindrome.\n");
}

int main (void) {
    printf("Enter a message: ");
    char msg[NCHARS+1] = "";
    read(msg);
    is_palindrome(msg);
}

void read(char *msg) {
    int ichar;
    for (ichar = 0; ichar < NCHARS; ichar++) {
        char c = getchar();
        if (c == '\n') {
            break;
        } else {
            msg[ichar] = c;
        }
    }
    if (ichar == NCHARS) {
        printf("Allocated memory full, ignoring any further input.\n");
    }
}
