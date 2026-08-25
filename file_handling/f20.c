//Create XML File

#include <stdio.h>

struct Employee
{
    int id;
    char name[30];
    char department[30];
    float salary;
};

int main()
{
    FILE *fp;
    struct Employee e;

    fp = fopen("employee.xml", "w");

    if (fp == NULL)
    {
        printf("File cannot be created\n");
        return 1;
    }

    scanf("%d", &e.id);
    scanf("%s", e.name);
    scanf("%s", e.department);
    scanf("%f", &e.salary);

    fprintf(fp, "<employee>\n");
    fprintf(fp, "    <id>%d</id>\n", e.id);
    fprintf(fp, "    <name>%s</name>\n", e.name);
    fprintf(fp, "    <department>%s</department>\n", e.department);
    fprintf(fp, "    <salary>%.2f</salary>\n", e.salary);
    fprintf(fp, "</employee>\n");

    fclose(fp);

    printf("Employee XML file created successfully\n");

    return 0;
}
