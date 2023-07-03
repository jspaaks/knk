#include <stdio.h>

#define NCHARS 1000

void read(char *message) {
    char *p = message;
    while (p - message < NCHARS) {
        int c = getchar();
        if (c == '\n') {
            break;
        }
        *p = c;
        p++;
    }
    if (p - message == NCHARS) {
        printf("Allocated memory full, ignoring the rest of the input.\n");
    }
};

void reverse(char *message) {
    char *p = message;
    char *q = message;
    while (*q != '\0') {
        q++;
    }
    q--;
    char c;
    while (p < q) {
        c = *p;
        *p = *q;
        *q = c;
        p++;
        q--;
    }
}

int main (void) {
    printf("Enter a message: ");
    char message[NCHARS+1] = "";
    read(message);
    printf("Message is : '%s'\n", message);
    reverse(message);
    printf("Reversed is: '%s'\n", message);
}
