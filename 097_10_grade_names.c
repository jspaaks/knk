#include <stdio.h>


int main (void) {

    int user_input_grade;

    printf("Please enter a numerical grade as an integer 0-100: ");
    scanf(" %d", &user_input_grade);

    if (user_input_grade < 0 || user_input_grade > 100) {
        printf("Invalid user input.");
    }

    int grade = user_input_grade / 10;
    char letter;

    switch (grade) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:  letter = 'F';
                 break;
        case 6:  letter = 'D';
                 break;
        case 7:  letter = 'C';
                 break;
        case 8:  letter = 'B';
                 break;
        case 9:
        case 10: letter = 'A';
                 break;
    }
    printf("The equivalent letter score of %d%% is %c.\n", user_input_grade, letter);

    return 0;

}
