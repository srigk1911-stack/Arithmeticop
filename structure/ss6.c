//date formate
#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

int main()
{
    struct Date date;

    scanf("%d", &date.day);
    scanf("%d", &date.month);
    scanf("%d", &date.year);

    printf("%02d/%02d/%04d", date.day, date.month, date.year);

    return 0;
}
