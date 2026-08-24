#include <stdio.h>

struct Student
{
    char name[50];
    struct
    {
        float mark1;
        float mark2;
        float mark3;
    } marks;
};

int main()
{
    struct Student s;
    float percentage;

    scanf("%s", s.name);
    scanf("%f", &s.marks.mark1);
    scanf("%f", &s.marks.mark2);
    scanf("%f", &s.marks.mark3);

    percentage = (s.marks.mark1 + s.marks.mark2 + s.marks.mark3) / 3;

    printf("%.2f", percentage);

    return 0;
}
