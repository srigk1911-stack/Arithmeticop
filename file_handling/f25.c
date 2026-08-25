//Convert CSV File into JSON File

#include <stdio.h>
#include <string.h>

struct Employee
{
    int id;
    char name[30];
    char department[30];
    float salary;
};

int main()
{
    FILE *csv, *json;
    struct Employee e;
    char line[100];

    csv = fopen("employee.csv", "r");
    json = fopen("employee.json", "w");

    if (csv == NULL || json == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    /* Skip CSV header */
    fgets(line, sizeof(line), csv);

    fprintf(json, "[\n");

    while (fscanf(csv, "%d,%29[^,],%29[^,],%f",
                  &e.id, e.name, e.department, &e.salary) == 4)
    {
        fprintf(json, "  {\n");
        fprintf(json, "    \"id\": %d,\n", e.id);
        fprintf(json, "    \"name\": \"%s\",\n", e.name);
        fprintf(json, "    \"department\": \"%s\",\n", e.department);
        fprintf(json, "    \"salary\": %.2f\n", e.salary);
        fprintf(json, "  }");

        if (!feof(csv))
            fprintf(json, ",");

        fprintf(json, "\n");
    }

    fprintf(json, "]\n");

    fclose(csv);
    fclose(json);

    printf("CSV file converted to JSON successfully\n");

    return 0;
}
