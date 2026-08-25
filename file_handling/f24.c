//Read JSON File

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char line[100];
    char value[50];

    fp = fopen("product.json", "r");

    if (fp == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (strstr(line, "\"id\"") != NULL)
        {
            sscanf(line, " \"id\": %s", value);
            printf("ID: %s\n", value);
        }
        else if (strstr(line, "\"name\"") != NULL)
        {
            sscanf(line, " \"name\": \"%[^\"]\"", value);
            printf("Name: %s\n", value);
        }
        else if (strstr(line, "\"price\"") != NULL)
        {
            sscanf(line, " \"price\": %s", value);
            printf("Price: %s\n", value);
        }
    }

    fclose(fp);

    return 0;
}
