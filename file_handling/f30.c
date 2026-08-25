// employee record management
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Employee
{
    int id;
    char name[30];
    char department[30];
    float salary;
};

void createEmployee()
{
    FILE *fp;
    struct Employee e;

    fp = fopen("employees.dat", "ab");

    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &e.id);

    printf("Enter Name: ");
    scanf("%s", e.name);

    printf("Enter Department: ");
    scanf("%s", e.department);

    printf("Enter Salary: ");
    scanf("%f", &e.salary);

    fwrite(&e, sizeof(e), 1, fp);

    fclose(fp);

    printf("Employee created successfully\n");
}

void readEmployees()
{
    FILE *fp;
    struct Employee e;

    fp = fopen("employees.dat", "rb");

    if (fp == NULL)
    {
        printf("No employee records found\n");
        return;
    }

    printf("\nEmployee Records\n");
    printf("-----------------------------\n");

    while (fread(&e, sizeof(e), 1, fp) == 1)
    {
        printf("ID: %d\n", e.id);
        printf("Name: %s\n", e.name);
        printf("Department: %s\n", e.department);
        printf("Salary: %.2f\n\n", e.salary);
    }

    fclose(fp);
}

void searchEmployee()
{
    FILE *fp;
    struct Employee e;
    int id, found = 0;

    fp = fopen("employees.dat", "rb");

    if (fp == NULL)
    {
        printf("File not found\n");
        return;
    }

    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    while (fread(&e, sizeof(e), 1, fp) == 1)
    {
        if (e.id == id)
        {
            printf("\nEmployee Found\n");
            printf("ID: %d\n", e.id);
            printf("Name: %s\n", e.name);
            printf("Department: %s\n", e.department);
            printf("Salary: %.2f\n", e.salary);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Employee not found\n");
    }

    fclose(fp);
}

void updateEmployee()
{
    FILE *fp;
    struct Employee e;
    int id, found = 0;

    fp = fopen("employees.dat", "rb+");

    if (fp == NULL)
    {
        printf("File not found\n");
        return;
    }

    printf("Enter Employee ID to update: ");
    scanf("%d", &id);

    while (fread(&e, sizeof(e), 1, fp) == 1)
    {
        if (e.id == id)
        {
            printf("Enter new salary: ");
            scanf("%f", &e.salary);

            fseek(fp, -sizeof(e), SEEK_CUR);
            fwrite(&e, sizeof(e), 1, fp);

            found = 1;
            printf("Employee updated successfully\n");
            break;
        }
    }

    if (!found)
    {
        printf("Employee not found\n");
    }

    fclose(fp);
}

void deleteEmployee()
{
    FILE *fp, *temp;
    struct Employee e;
    int id, found = 0;

    fp = fopen("employees.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL)
    {
        printf("File cannot be opened\n");
        return;
    }

    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    while (fread(&e, sizeof(e), 1, fp) == 1)
    {
        if (e.id == id)
        {
            found = 1;
        }
        else
        {
            fwrite(&e, sizeof(e), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("employees.dat");
    rename("temp.dat", "employees.dat");

    if (found)
        printf("Employee deleted successfully\n");
    else
        printf("Employee not found\n");
}

void exportCSV()
{
    FILE *fp, *csv;
    struct Employee e;

    fp = fopen("employees.dat", "rb");
    csv = fopen("employees.csv", "w");

    if (fp == NULL || csv == NULL)
    {
        printf("File cannot be opened\n");
        return;
    }

    fprintf(csv, "ID,Name,Department,Salary\n");

    while (fread(&e, sizeof(e), 1, fp) == 1)
    {
        fprintf(csv, "%d,%s,%s,%.2f\n",
                e.id, e.name, e.department, e.salary);
    }

    fclose(fp);
    fclose(csv);

    printf("CSV report exported successfully\n");
}

void exportXML()
{
    FILE *fp, *xml;
    struct Employee e;

    fp = fopen("employees.dat", "rb");
    xml = fopen("employees.xml", "w");

    if (fp == NULL || xml == NULL)
    {
        printf("File cannot be opened\n");
        return;
    }

    fprintf(xml, "<employees>\n");

    while (fread(&e, sizeof(e), 1, fp) == 1)
    {
        fprintf(xml, "  <employee>\n");
        fprintf(xml, "    <id>%d</id>\n", e.id);
        fprintf(xml, "    <name>%s</name>\n", e.name);
        fprintf(xml, "    <department>%s</department>\n", e.department);
        fprintf(xml, "    <salary>%.2f</salary>\n", e.salary);
        fprintf(xml, "  </employee>\n");
    }

    fprintf(xml, "</employees>\n");

    fclose(fp);
    fclose(xml);

    printf("XML report exported successfully\n");
}

void exportJSON()
{
    FILE *fp, *json;
    struct Employee e;
    int first = 1;

    fp = fopen("employees.dat", "rb");
    json = fopen("employees.json", "w");

    if (fp == NULL || json == NULL)
    {
        printf("File cannot be opened\n");
        return;
    }

    fprintf(json, "[\n");

    while (fread(&e, sizeof(e), 1, fp) == 1)
    {
        if (!first)
            fprintf(json, ",\n");

        fprintf(json, "  {\n");
        fprintf(json, "    \"id\": %d,\n", e.id);
        fprintf(json, "    \"name\": \"%s\",\n", e.name);
        fprintf(json, "    \"department\": \"%s\",\n", e.department);
        fprintf(json, "    \"salary\": %.2f\n", e.salary);
        fprintf(json, "  }");

        first = 0;
    }

    fprintf(json, "\n]\n");

    fclose(fp);
    fclose(json);

    printf("JSON report exported successfully\n");
}

void createLog()
{
    FILE *fp;
    time_t now;

    fp = fopen("employee.log", "a");

    if (fp == NULL)
        return;

    now = time(NULL);

    fprintf(fp, "Operation completed at %s", ctime(&now));

    fclose(fp);

    printf("Log file updated successfully\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n===== Employee Management System =====\n");
        printf("1. Create Employee\n");
        printf("2. Read Employees\n");
        printf("3. Update Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Search Employee\n");
        printf("6. Export CSV\n");
        printf("7. Export XML\n");
        printf("8. Export JSON\n");
        printf("9. Create Log\n");
        printf("10. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createEmployee();
                break;

            case 2:
                readEmployees();
                break;

            case 3:
                updateEmployee();
                break;

            case 4:
                deleteEmployee();
                break;

            case 5:
                searchEmployee();
                break;

            case 6:
                exportCSV();
                break;

            case 7:
                exportXML();
                break;

            case 8:
                exportJSON();
                break;

            case 9:
                createLog();
                break;

            case 10:
                printf("Program exited\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 10);

    return 0;
}
