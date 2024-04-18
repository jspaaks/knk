#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define NRANKS 13
#define NSUITS 4
#define NCARDS 5

// EXTERNAL VARIABLES

bool isstraight;
bool isflush;
bool isfour;
bool isthree;
int npairs;


void analyze_hand (int in_rank_count[NRANKS], int in_suit_count[NSUITS]);
void print_result (bool in_hand[NRANKS][NSUITS], int in_rank_count[NRANKS], int in_suit_count[NSUITS]);
void read_cards (bool in_hand[NRANKS][NSUITS], int in_rank_count[NRANKS], int in_suit_count[NSUITS]);


void analyze_hand (int in_rank_count[NRANKS], int in_suit_count[NSUITS]) {

    // initialize
    isstraight = false;
    isflush = false;
    isfour = false;
    isthree = false;
    npairs = 0;

    // check for flush
    for (int isuit = 0; isuit < NSUITS; isuit++) {
        if (in_suit_count[isuit] == NCARDS) {
            isflush = true;
        }
    }

    // check for straight
    int nconsec = 0;
    for (int irank = 0; irank < NRANKS; irank++) {
        if (in_rank_count[irank] > 0) {
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
        if (in_rank_count[irank] == 4) {
            isfour = true;
        }
        if (in_rank_count[irank] == 3) {
            isthree = true;
        }
        if (in_rank_count[irank] == 2) {
            npairs += 1;
        }
    }

    return;
}


int main (void) {

    bool in_hand[NRANKS][NSUITS];
    int in_rank_count[NRANKS];
    int in_suit_count[NSUITS];

    printf("This program classifies a poker hand of %d cards.\n", NCARDS);

    for (;;) {
        read_cards(in_hand, in_rank_count, in_suit_count);
        analyze_hand(in_rank_count, in_suit_count);
        print_result(in_hand, in_rank_count, in_suit_count);
    }

    return 0;

}


void print_result (bool in_hand[NRANKS][NSUITS], int in_rank_count[NRANKS], int in_suit_count[NSUITS]) {

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
            if (in_hand[irank][isuit] == true) {
                putchar('x');
            } else {
                putchar('.');
            }
        }

        int n = in_suit_count[isuit];
        if (n > 0) {
            printf(" %d\n", in_suit_count[isuit]);
        } else {
            printf("\n");
        }
    }

    printf("          ");
    for (int irank = 0; irank < NRANKS; irank++) {
        int n = in_rank_count[irank];
        if (n > 0) {
            printf("%d", n);
        } else {
            printf(" ");
        }
    }

    printf("\n");

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


void read_cards (bool in_hand[NRANKS][NSUITS], int in_rank_count[NRANKS], int in_suit_count[NSUITS]) {

    bool is_bad;
    int ncards_read = 0;

    for (int irank = 0; irank < NRANKS; irank++) {
        for (int isuit = 0; isuit < NSUITS; isuit++) {
            if (irank == 0) {
                in_suit_count[isuit] = 0;
            }
            if (isuit == 0) {
                in_rank_count[irank] = 0;
            }
            in_hand[irank][isuit] = false;
        }
    }

    int irank;
    int isuit;

    while (ncards_read < NCARDS) {

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

        } else if (in_hand[irank][isuit] == true) {

            printf("Duplicate card, ignored.\n");

        } else {

            in_rank_count[irank] += 1;
            in_suit_count[isuit] += 1;
            in_hand[irank][isuit] = true;
            ncards_read += 1;

        }


    }

    return;
}



