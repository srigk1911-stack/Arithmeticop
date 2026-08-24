//program to calculate the age of a person using a Date of Birth structure

#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

int main()
{
    struct Date dob, current;
    int age;

    scanf("%d", &dob.day);
    scanf("%d", &dob.month);
    scanf("%d", &dob.year);

    scanf("%d", &current.day);
    scanf("%d", &current.month);
    scanf("%d", &current.year);

    age = current.year - dob.year;

    if (current.month < dob.month ||
        (current.month == dob.month && current.day < dob.day))
    {
        age--;
    }

    printf("%d", age);

    return 0;
}
