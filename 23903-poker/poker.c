#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define NRANKS 13
#define NSUITS 4
#define NCARDS 5
#define RANKCOL 0
#define SUITCOL 1

// EXTERNAL VARIABLES

bool isstraight;
bool isflush;
bool isfour;
bool isthree;
int npairs;


void analyze_hand (int hand[NCARDS][2]);
int count_suit (int hand[NCARDS][2], int isuit);
int count_rank (int hand[NCARDS][2], int irank);
bool isduplicate(int hand[NCARDS][2], int irank, int isuit);
void print_result (int hand[NCARDS][2]);
void read_cards (int hand[NCARDS][2]);


void analyze_hand (int hand[NCARDS][2]) {

    // initialize
    isstraight = false;
    isflush = false;
    isfour = false;
    isthree = false;
    npairs = 0;

    // check for flush
    for (int isuit = 0; isuit < NSUITS; isuit++) {
        int nsuits = count_suit(hand, isuit);
        if (nsuits == NCARDS) {
            isflush = true;
        }
    }

    // check for straight
    int nconsec = 0;
    for (int irank = 0; irank < NRANKS; irank++) {
        int n = count_rank(hand, irank);
        if (n > 0) {
            nconsec += 1;
        } else {
            nconsec = 0;
        }
        if (nconsec == NCARDS) {
            isstraight = true;
        }
    }

    // check for four-of-a-kind, three-of-a-kind, pairs
    for (int irank = 0; irank < NRANKS; irank++) {
        int n = count_rank(hand, irank);
        if (n == 4) {
            isfour = true;
        }
        if (n == 3) {
            isthree = true;
        }
        if (n == 2) {
            npairs += 1;
        }
    }

    return;
}


int count_suit (int hand[NCARDS][2], int isuit) {
    int n = 0;
    for (int icard = 0; icard < NCARDS; icard++) {
        if (hand[icard][SUITCOL] == isuit) {
            n += 1;
        }
    }
    return n;
}



int count_rank (int hand[NCARDS][2], int irank) {
    int n = 0;
    for (int icard = 0; icard < NCARDS; icard++) {
        if (hand[icard][RANKCOL] == irank) {
            n += 1;
        }
    }
    return n;
}


bool isduplicate(int hand[NCARDS][2], int irank, int isuit) {

    for (int icard = 0; icard < NCARDS; icard++ ) {
        if (hand[icard][RANKCOL] == irank && hand[icard][SUITCOL] == isuit) {
            return true;
        }
    }
    return false;
}


int main (void) {

    int hand[NCARDS][2];

    printf("This program classifies a poker hand of %d cards.\n", NCARDS);

    for (;;) {
        read_cards(hand);
        analyze_hand(hand);
        print_result(hand);
    }

    return 0;

}


void print_result (int hand[NCARDS][2]) {

    printf("          23456789TJQKA\n");

    for (int isuit = 0; isuit < NSUITS; isuit++) {

        if (isuit == 0) {
            printf("clubs   : ");
        } else if (isuit == 1) {
            printf("diamonds: ");
        } else if (isuit == 2) {
            printf("hearts  : ");
        } else if (isuit == 3) {
            printf("spades  : ");
        }

        for (int irank = 0; irank < NRANKS; irank++) {

            bool dup = isduplicate(hand, irank, isuit);

            if (dup == true) {
                printf("x");
            } else {
                printf(".");
            }

        }
        printf("\n");
    }

    if (isstraight == true && isflush == true) {
        printf("Straight flush\n");
    } else if (isfour == true) {
        printf("Four of a kind\n");
    } else if (isthree == true && npairs == 1) {
        printf("Full house\n");
    } else if (isflush == true) {
        printf("Flush\n");
    } else if (isstraight == true) {
        printf("Straight\n");
    } else if (isthree == true) {
        printf("Three of a kind\n");
    } else if (npairs == 2) {
        printf("Two pairs\n");
    } else if (npairs == 1) {
        printf("Pair\n");
    } else {
        printf("High card\n");
    }

    return;
}


void read_cards (int hand[NCARDS][2]) {

    bool is_bad;
    int irank;
    int isuit;
    int icard = 0;

    for (int icard = 0; icard < NCARDS; icard++) {
        hand[icard][RANKCOL] = -1;
        hand[icard][SUITCOL] = -1;
    }

    while (icard < NCARDS) {

        is_bad = false;

        printf("Enter a card (0 to terminate): ");

        char ch_rank = tolower(getchar());

        switch (ch_rank) {
            case '0': {
                exit(EXIT_SUCCESS);
            }
            case '2': {
                irank = 0;
                break;
            }
            case '3': {
                irank = 1;
                break;
            }
            case '4': {
                irank = 2;
                break;
            }
            case '5': {
                irank = 3;
                break;
            }
            case '6': {
                irank = 4;
                break;
            }
            case '7': {
                irank = 5;
                break;
            }
            case '8': {
                irank = 6;
                break;
            }
            case '9': {
                irank = 7;
                break;
            }
            case 't': {
                irank = 8;
                break;
            }
            case 'j': {
                irank = 9;
                break;
            }
            case 'q': {
                irank = 10;
                break;
            }
            case 'k': {
                irank = 11;
                break;
            }
            case 'a': {
                irank = 12;
                break;
            }
            default: {
                is_bad = true;
                break;
            }
        }

        char ch_suit = tolower(getchar());

        switch (ch_suit) {
            case 'c': {
                isuit = 0;
                break;
            }
            case 'd': {
                isuit = 1;
                break;
            }
            case 'h': {
                isuit = 2;
                break;
            }
            case 's': {
                isuit = 3;
                break;
            }
            default: {
                is_bad = true;
                break;
            }
        }

        // gobble up any more characters
        while (true) {

            char c = getchar();

            if (c == ' ') {
               continue;
            } else if (c == '\n') {
                break;
            } else {
                is_bad = true;
            }
        }

        if (is_bad) {
            printf("Invalid card, ignored.\n");
            continue;
        }

        if ( isduplicate(hand, irank, isuit) ) {
            printf("Duplicate card, ignored.\n");
            continue;
        }

        hand[icard][RANKCOL] = irank;
        hand[icard][SUITCOL] = isuit;
        icard += 1;

    }

    return;
}


