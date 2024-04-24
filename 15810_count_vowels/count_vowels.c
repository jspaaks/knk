#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


int main (void) {

    printf("Enter a sentence: ");

    int nvowels = 0;
    int na = 0;
    int ne = 0;
    int ni = 0;
    int no = 0;
    int nu = 0;

    while (true) {

        int c = getchar();
        c = tolower(c);

        if (c == '\n') {
            break;
        } else if (c == 'a') {
            nvowels += 1;
            na += 1;
        } else if (c == 'e') {
            nvowels += 1;
            ne += 1;
        } else if (c == 'i') {
            nvowels += 1;
            ni += 1;
        } else if (c == 'o') {
            nvowels += 1;
            no += 1;
        } else if (c == 'u') {
            nvowels += 1;
            nu += 1;
        }
    }

    printf("Your sentence contains %d vowels. Vowel count breakdown: \n", nvowels);

    printf("a: ");
    for (int ia = 0; ia < na; ia++) {
        printf("%1c", 24);
    }
    printf("\n");

    printf("e: ");
    for (int ie = 0; ie < ne; ie++) {
        printf("%1c", 24);
    }
    printf("\n");

    printf("i: ");
    for (int ii = 0; ii < ni; ii++) {
        printf("%1c", 24);
    }
    printf("\n");

    printf("o: ");
    for (int io = 0; io < no; io++) {
        printf("%1c", 24);
    }
    printf("\n");

    printf("u: ");
    for (int iu = 0; iu < nu; iu++) {
        printf("%1c", 24);
    }
    printf("\n");

    return 0;

}
