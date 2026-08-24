//Write a C program to compare the marks of two students using structures and display the topper.
#include <stdio.h>

struct Student
{
    char name[50];
    float marks;
};

int main()
{
    struct Student s1, s2;

    scanf("%s", s1.name);
    scanf("%f", &s1.marks);

    scanf("%s", s2.name);
    scanf("%f", &s2.marks);

    if (s1.marks > s2.marks)
        printf("%s", s1.name);
    else if (s2.marks > s1.marks)
        printf("%s", s2.name);
    else
        printf("Both");

    return 0;
}
