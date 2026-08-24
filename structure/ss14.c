//updating salary
#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
};

void updateSalary(struct Employee *e)
{
    e->salary = e->salary + 5000;
}

int main()
{
    struct Employee e;

    scanf("%d", &e.id);
    scanf("%s", e.name);
    scanf("%f", &e.salary);

    updateSalary(&e);

    printf("%.2f", e.salary);

    return 0;
}
