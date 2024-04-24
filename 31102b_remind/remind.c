#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50 /* maximum number of reminders    */
#define MSG_LENGTH 60 /* max length of reminder message */

int read_line(char str[], int n);

int main (void) {
    char reminders[MAX_REMIND][MSG_LENGTH + 3];
    char day_time_str[8 + 1], msg_str[MSG_LENGTH + 1];
    int day, hours, minutes, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left  --\n");
            break;
        }
        printf("Enter day, time (HH:mm), and reminder: ");
        scanf("%2d", &day);
        if (day == 0)
            break;
        scanf("%2d:%2d", &hours, &minutes);
        sprintf(day_time_str, "%2d %2d:%02d", day, hours, minutes);
        read_line(msg_str, MSG_LENGTH);

        if (0 > hours || hours > 23)
            continue;
        if (0 > minutes || minutes > 59)
            continue;

        for (i = 0; i < num_remind; i++)
            if (strcmp(day_time_str, reminders[i]) < 0)
                break;

        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j - 1]);

        strcpy(reminders[i], day_time_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);

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
