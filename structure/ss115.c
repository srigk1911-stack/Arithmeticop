//C program to return a structure from a function after reading employee details
#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
};

struct Employee readEmployee()
{
    struct Employee e;

    scanf("%d", &e.id);
    scanf("%s", e.name);
    scanf("%f", &e.salary);

    return e;
}

int main()
{
    struct Employee e;

    e = readEmployee();

    printf("%d\n", e.id);
    printf("%s\n", e.name);
    printf("%.2f\n", e.salary);

    return 0;
}

