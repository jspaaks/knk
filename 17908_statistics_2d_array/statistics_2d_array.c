#include <stdio.h>
#include <stdbool.h>

#define NSTUDENTS 8
#define NQUIZZES 5


int main (void) {

    int numbers[NSTUDENTS][NQUIZZES];
    int nstudents = (int) (sizeof(numbers) / sizeof(numbers[0]));
    int nquizzes = (int) (sizeof(numbers[0]) / sizeof(numbers[0][0]));


    // prompt user for input and collect the numbers
    for (int istudent = 0; istudent < nstudents; istudent++) {
        printf("Enter the grades (0 - 10) of student %d for each of %d quizzes: ", istudent + 1, nquizzes);
        for (int iquiz = 0; iquiz < nquizzes; iquiz++) {
             scanf("%d", &numbers[istudent][iquiz]);
        }

        // gobble up any trailing data for this student
        while (true) {
            int c = getchar();
            if (c == '\n') {
                break;
            } else if (c == ' ') {
                continue;
            } else {
                printf("Ignoring extra data for student %d.\n", istudent + 1);
            }
        }

        // check if the student's numbers are all within range
        for (int iquiz = 0; iquiz < nquizzes; iquiz++) {
            int tmp = numbers[istudent][iquiz];
            if (tmp < 0 || tmp > 10) {
                printf("Input out of range, please enter grades again.\n");
                istudent--;
                continue;
            }
        }
    }

    // calculate row sums
    double rowsums[NSTUDENTS];
    for (int istudent = 0; istudent < nstudents; istudent++) {
        rowsums[istudent] = 0;
        for (int iquiz = 0; iquiz < nquizzes ; iquiz++) {
            rowsums[istudent] += numbers[istudent][iquiz];
        }
    }

    // calculate col sums, col mins, col maxes
    double colsums[NQUIZZES];
    double colmins[NQUIZZES];
    double colmaxs[NQUIZZES];
    for (int iquiz = 0; iquiz < nquizzes ; iquiz++) {
        colsums[iquiz] = 0;
        for (int istudent = 0; istudent < nstudents; istudent++) {
            colsums[iquiz] += numbers[istudent][iquiz];
            if (numbers[istudent][iquiz] < colmins[iquiz] || istudent == 0) {
                colmins[iquiz] = numbers[istudent][iquiz];
            }
            if (numbers[istudent][iquiz] > colmaxs[iquiz] || istudent == 0) {
                colmaxs[iquiz] = numbers[istudent][iquiz];
            }
        }
    }

    // print the headers
    char indent[] = "         |";
    printf("\nOVERVIEW\n");
    printf("student  |");
    for (int iquiz = 0; iquiz < nquizzes; iquiz++) {
        printf("q%-3d|", iquiz + 1);
    }
    printf("sum |avg");
    printf("\n");
    printf("---------|");
    for (int iquiz = 0; iquiz < nquizzes; iquiz++) {
        printf("----|");
    }
    printf("----|----");
    printf("\n");
    for (int istudent = 0; istudent < nstudents; istudent++) {
        // print the grades
        printf("        %d|", istudent + 1);
        for (int iquiz = 0; iquiz < nquizzes; iquiz++) {
            printf("%4d|", numbers[istudent][iquiz]);
        }

        // print the row sums
        printf("%4.1f|", rowsums[istudent]);
        printf("%4.1f",  rowsums[istudent] / nquizzes);
        printf("\n");
    }
    printf("%s", indent);
    for (int iquiz = 0; iquiz < nquizzes; iquiz++) {
        printf("----|");
    }
    printf("\n");

    // print the col minimums
    printf("      low|");
    for (int iquiz = 0; iquiz < nquizzes; iquiz++) {
        printf("%4.1f|", colmins[iquiz]);
    }
    printf("\n");
    // print the col average
    printf("      avg|");
    for (int iquiz = 0; iquiz < nquizzes; iquiz++) {
        printf("%4.1f|", colsums[iquiz] / nstudents);
    }
    printf("\n");
    // print the col maximums
    printf("     high|");
    for (int iquiz = 0; iquiz < nquizzes; iquiz++) {
        printf("%4.1f|", colmaxs[iquiz]);
    }
    printf("\n");

    return 0;

}

/* Example output

Enter the grades (0 - 10) of student 1 for each of 5 quizzes: 2 3 5 6 2
Enter the grades (0 - 10) of student 2 for each of 5 quizzes: 7 7 4 5 9
Enter the grades (0 - 10) of student 3 for each of 5 quizzes: 4 2 3 4 5
Enter the grades (0 - 10) of student 4 for each of 5 quizzes: 3 7 4 6 8
Enter the grades (0 - 10) of student 5 for each of 5 quizzes: 9 9 6 8 7
Enter the grades (0 - 10) of student 6 for each of 5 quizzes: 6 5 4 6 6
Enter the grades (0 - 10) of student 7 for each of 5 quizzes: 3 7 9 6 5
Enter the grades (0 - 10) of student 8 for each of 5 quizzes: 7 3 6 8 9

OVERVIEW
student  |q1  |q2  |q3  |q4  |q5  |sum |avg
---------|----|----|----|----|----|----|----
        1|   2|   3|   5|   6|   2|18.0| 3.6
        2|   7|   7|   4|   5|   9|32.0| 6.4
        3|   4|   2|   3|   4|   5|18.0| 3.6
        4|   3|   7|   4|   6|   8|28.0| 5.6
        5|   9|   9|   6|   8|   7|39.0| 7.8
        6|   6|   5|   4|   6|   6|27.0| 5.4
        7|   3|   7|   9|   6|   5|30.0| 6.0
        8|   7|   3|   6|   8|   9|33.0| 6.6
         |----|----|----|----|----|
      low| 2.0| 2.0| 3.0| 4.0| 2.0|
      avg| 5.1| 5.4| 5.1| 6.1| 6.4|
     high| 9.0| 9.0| 9.0| 8.0| 9.0|

*/
