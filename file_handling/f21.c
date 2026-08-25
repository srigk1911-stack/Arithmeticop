//Read XML File and Extract Values

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char line[100];
    char value[50];

    fp = fopen("employee.xml", "r");

    if (fp == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (strstr(line, "<id>") != NULL)
        {
            sscanf(line, " <id>%[^<]</id>", value);
            printf("ID: %s\n", value);
        }
        else if (strstr(line, "<name>") != NULL)
        {
            sscanf(line, " <name>%[^<]</name>", value);
            printf("Name: %s\n", value);
        }
        else if (strstr(line, "<department>") != NULL)
        {
            sscanf(line, " <department>%[^<]</department>", value);
            printf("Department: %s\n", value);
        }
        else if (strstr(line, "<salary>") != NULL)
        {
            sscanf(line, " <salary>%[^<]</salary>", value);
            printf("Salary: %s\n", value);
        }
    }

    fclose(fp);

    return 0;
}
