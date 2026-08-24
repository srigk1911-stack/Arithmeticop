// students details user defined
#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    float marks;
};

void readStudent(struct Student *s)
{
    scanf("%d", &s->roll);
    scanf("%s", s->name);
    scanf("%f", &s->marks);
}

void displayStudent(struct Student s)
{
    printf("%d\n", s.roll);
    printf("%s\n", s.name);
    printf("%.2f\n", s.marks);
}

int main()
{
    struct Student s;

    readStudent(&s);
    displayStudent(s);

    return 0;
}
