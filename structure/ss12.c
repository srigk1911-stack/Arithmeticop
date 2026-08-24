//pass astructure to a function
#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    float marks;
};

void display(struct Student s)
{
    printf("%d\n", s.roll);
    printf("%s\n", s.name);
    printf("%.2f\n", s.marks);
}

int main()
{
    struct Student s;

    scanf("%d", &s.roll);
    scanf("%s", s.name);
    scanf("%f", &s.marks);

    display(s);

    return 0;
}
