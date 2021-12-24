#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>


void initialize_pseudorandom(void);
bool play_again(void);
bool play_game(void);
int roll_dice(void);
void show_roll(int dice0, int dice1, int sum);


void initialize_pseudorandom(void) {
    unsigned int t = (unsigned int) time(NULL);
    srand(t);
}


int main (void) {

    int wins = 0;
    int losses = 0;

    initialize_pseudorandom();

    while (true) {

        bool result = play_game();

        if (result == true) {
            wins += 1;
        } else {
            losses += 1;
        }

        if (play_again() == true) {
            continue;
        } else {
            printf("Wins: %d Losses: %d\n", wins, losses);
            printf("Thanks for playing!\n");
            exit(EXIT_SUCCESS);
        }
    }

}

bool play_again (void) {

    printf("Play again? ([y] / n): ");

    char c;
    bool result;

    while (true) {

        c = getchar();

        if (c == ' ') {
            continue;
        } else if (c == 'y' || c == 'Y' || c == '\n') {
            result = true;
            break;
        } else {
            result = false;
            break;
        }
    }
    while (c != '\n') {
        c = getchar();
    }
    return result;
}


bool play_game(void) {

    int point;
    int sum;

    for (int i = 0; i < 40; i++) {
        putchar('-');
    }
    putchar('\n');

    sum = roll_dice();

    if (sum == 7 || sum == 11) {
        printf("You win!\n");
        return true;
    } else if (sum == 2 || sum == 3 || sum == 12) {
        printf("You lose!\n");
        return false;
    } else {
        point = sum;
        printf("Your point is %d\n", point);
    }

    int nrolls = 0;

    while (true) {

        sum = roll_dice();
        nrolls += 1;
        if (sum == point) {
            printf("You win!");
            if (nrolls > 10) {
                printf(" What a game!\n");
            } else {
                printf("\n");
            }
            return true;
        } else if (sum == 7) {
            printf("You lose!\n");
            return false;
        }

    }

}


int roll_dice(void) {

    int dice0 = 1 + rand() % 6;
    int dice1 = 1 + rand() % 6;
    int sum = dice0 + dice1;
    printf("You rolled %d and %d for a total of %d\n", dice0, dice1, sum);
    return sum;
}
