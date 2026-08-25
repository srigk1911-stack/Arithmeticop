//csv

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Employee
{
    int id;
    char name[30];
    float salary;
};

int main()
{
    FILE *fp;
    char line[100];
    char *token;
    struct Employee e;

    fp = fopen("employee.csv", "w");

    if (fp == NULL)
    {
        printf("File cannot be created\n");
        return 1;
    }

    fprintf(fp, "ID,Name,Salary\n");
    fprintf(fp, "101,Arun,45000\n");
    fprintf(fp, "102,Bala,60000\n");
    fprintf(fp, "103,Kavi,75000\n");
    fprintf(fp, "104,Ravi,40000\n");

    fclose(fp);

    fp = fopen("employee.csv", "r");

    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    fgets(line, sizeof(line), fp);

    printf("Employees with salary greater than 50000:\n");

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        token = strtok(line, ",");
        e.id = atoi(token);

        token = strtok(NULL, ",");
        strcpy(e.name, token);

        token = strtok(NULL, ",");
        e.salary = atof(token);

        if (e.salary > 50000)
        {
            printf("ID: %d\n", e.id);
            printf("Name: %s", e.name);
            printf("Salary: %.2f\n\n", e.salary);
        }
    }

    fclose(fp);

    return 0;
}
