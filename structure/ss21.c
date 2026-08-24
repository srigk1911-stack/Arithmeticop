//C program to swap two structures using a temporary structure variable.

#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
};

int main()
{
    struct Student s1, s2, temp;

    scanf("%d", &s1.roll);
    scanf("%s", s1.name);

    scanf("%d", &s2.roll);
    scanf("%s", s2.name);

    temp = s1;
    s1 = s2;
    s2 = temp;

    printf("%d %s\n", s1.roll, s1.name);
    printf("%d %s", s2.roll, s2.name);

    return 0;
}
