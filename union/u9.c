//students details

#include <stdio.h>

union Student
{
    int roll;
    float cgpa;
    char grade;
};

int main()
{
    union Student s;

    s.roll = 101;
    printf("%d\n", s.roll);

    s.cgpa = 8.5;
    printf("%.2f\n", s.cgpa);

    s.grade = 'A';
    printf("%c\n", s.grade);

    return 0;
}
