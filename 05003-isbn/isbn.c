#include <stdio.h>

int main (void) {

    int gs1;
    int group_id;
    int publisher_id;
    int item_id;
    int check_digit;

    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &gs1, &group_id, &publisher_id, &item_id, &check_digit);
    printf("GS1 prefix: %d\n", gs1);
    printf("Group identifier: %d\n", group_id);
    printf("Publisher identifier: %d\n", publisher_id);
    printf("Item identifier: %d\n", item_id);
    printf("Check digit: %d\n", check_digit);

    return 0;

}
