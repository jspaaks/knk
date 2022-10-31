#include <stdio.h>

#define LEN 1000

void print_msg_indices(char msg[], int nchars);
void print_msg_pointers(char msg[], int nchars);

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
    print_msg_indices(msg, nchars);
    print_msg_pointers(msg, nchars);
}


void print_msg_indices(char msg[], int nchars) {
    for (int ichar = nchars - 1; ichar >= 0; ichar--) {
        printf("%c", msg[ichar]);
    }
    printf("\n");
}

void print_msg_pointers(char msg[], int nchars) {
    for (char *i = &msg[nchars - 1]; i >= &msg[0]; i--) {
        printf("%c", *i);
    }
    printf("\n");
}
