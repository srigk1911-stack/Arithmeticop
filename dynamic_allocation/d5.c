//C program to dynamically allocate memory for one structure variable containing roll_no, name, and department. Access the structure members using a structure pointer

#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int roll_no;
    char name[30];
    char department[30];
};

int main()
{
    struct Student *s;

    s = (struct Student *)malloc(sizeof(struct Student));

    scanf("%d", &s->roll_no);
    scanf("%s", s->name);
    scanf("%s", s->department);

    printf("%d\n", s->roll_no);
    printf("%s\n", s->name);
    printf("%s\n", s->department);

    free(s);

    return 0;
}
