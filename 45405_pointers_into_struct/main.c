#include <stdio.h>

int main (void) {
    struct {
        union {
            char a;
            char b;
            int c;
        } d;

        int e[5];
    } f, *p = &f;

    // a) p->b invalid need to go through union member first p->d.b
    printf("a) p->b = ' ';      invalid, use p->d.b = ' ';\n");
    p->d.b = ' ';

    // b) valid
    printf("b) p->e[3];         valid\n");
    p->e[3] = 10;

    // c) valid
    printf("c) (*p).d.a;        valid\n");
    (*p).d.a = '*';

    // d) invalid, d is not a pointer.
    printf("d) p->d->c = 20;    invalid, use p->d.c = 20;\n");
    p->d.c = 20;
}
