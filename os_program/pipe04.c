#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
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

    emp = malloc(sizeof(struct Employee));

    if (emp == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &emp->id);

    printf("Enter Employee Name: ");
    scanf("%s", emp->name);

    printf("Enter Department: ");
    scanf("%s", emp->department);

    printf("Enter Monthly Salary: ");
    scanf("%f", &emp->salary);

    mkfifo("/tmp/employee_fifo", 0666);

    fd = open("/tmp/employee_fifo", O_WRONLY);

    write(fd, emp, sizeof(struct Employee));

    close(fd);

    free(emp);

    return 0;
}
