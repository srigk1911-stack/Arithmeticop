#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

struct Employee
{
    int id;
    char name[50];
    char department[50];
    float salary;
};

int main()
{
    int fd;
    struct Employee *emp;
    float annual_salary;

    emp = malloc(sizeof(struct Employee));

    if (emp == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    fd = open("/tmp/employee_fifo", O_RDONLY);

    read(fd, emp, sizeof(struct Employee));

    close(fd);

    annual_salary = emp->salary * 12;

    printf("\nEmployee Details\n");
    printf("ID = %d\n", emp->id);
    printf("Name = %s\n", emp->name);
    printf("Department = %s\n", emp->department);
    printf("Monthly Salary = %.2f\n", emp->salary);
    printf("Annual Salary = %.2f\n", annual_salary);

    if (annual_salary >= 600000)
    {
        printf("Salary Category = High\n");
    }
    else if (annual_salary >= 300000)
    {
        printf("Salary Category = Medium\n");
    }
    else
    {
        printf("Salary Category = Low\n");
    }

    free(emp);

    unlink("/tmp/employee_fifo");

    return 0;
}
