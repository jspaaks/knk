#include <stdio.h>


int main (void) {

    int id;
    float unit_price;
    int date_month, date_dom, date_year;

    printf("Enter item id: ");
    scanf("%d", &id);

    printf("Enter unit price: ");
    scanf("%f", &unit_price);

    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d / %d / %d", &date_month, &date_dom, &date_year);

    printf("%-16s%-16s%-16s\n", "Item", "Unit", "Purchase");
    printf("%-16s%-16s%-16s\n", "", "Price", "Date");
    printf("%-16d$%7.2f        %d/%d/%d\n", id, unit_price, date_month, date_dom, date_year);

    return 0;

}
