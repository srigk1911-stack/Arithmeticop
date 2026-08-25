//Update a Specific XML Tag Value

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp, *temp;
    char line[100];
    char newName[30];

    fp = fopen("employee.xml", "r");
    temp = fopen("temp.xml", "w");

    if (fp == NULL || temp == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    scanf("%s", newName);

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (strstr(line, "<name>") != NULL)
        {
            fprintf(temp, "    <name>%s</name>\n", newName);
        }
        else
        {
            fputs(line, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("employee.xml");
    rename("temp.xml", "employee.xml");

    printf("Name updated successfully\n");

    return 0;
}
