//employee details
#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
};

int main()
{
    struct Employee emp;

    scanf("%d", &emp.id);
    scanf("%s", emp.name);
    scanf("%f", &emp.salary);

    printf("%d\n", emp.id);
    printf("%s\n", emp.name);
    printf("%.2f\n", emp.salary);

    return 0;
}
