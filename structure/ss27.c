//C program to use typedef for declaring structures
#include <stdio.h>

typedef struct
{
    int roll;
    char name[50];
    float marks;
} Student;

int main()
{
    Student s;

    scanf("%d", &s.roll);
    scanf("%s", s.name);
    scanf("%f", &s.marks);

    printf("%d\n", s.roll);
    printf("%s\n", s.name);
    printf("%.2f", s.marks);

    return 0;
}
