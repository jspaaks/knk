#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50 /* maximum number of reminders    */
#define MSG_LENGTH 60 /* max length of reminder message */

int read_line(char str[], int n);

int main (void) {
    char reminders[MAX_REMIND][MSG_LENGTH + 5 + 1];
    char sort_by_str[5 + 1];
    char msg_str[MSG_LENGTH + 1];
    int day, month, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left  --\n");
            break;
        }
        printf("Enter date as mm/dd, followed by the reminder: ");
        scanf("%2d/%2d", &month, &day);

        if (month == 0) {
            printf("User terminated input\n");
            break;
        }

        sprintf(sort_by_str, "%2d/%2d", month, day);
        read_line(msg_str, MSG_LENGTH);

        if (day < 1 || day > 31) {
            printf("Invalid day input, try again\n");
            continue;
        }

        if (month < 1 || month > 12) {
            printf("Invalid month input, try again\n");
            continue;
        }

        for (i = 0; i < num_remind; i++)
            if (strcmp(sort_by_str, reminders[i]) < 0)
                break;

        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j - 1]);

        strcpy(reminders[i], sort_by_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    if (num_remind > 0) {
        printf("\ndate  Reminder\n");
        for (i = 0; i < num_remind; i++)
            printf(" %s\n", reminders[i]);
    }
    return 0;
}

int read_line(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < n) 
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}
