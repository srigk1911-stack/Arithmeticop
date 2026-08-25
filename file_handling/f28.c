//Analyze Log File

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char line[200];

    int info = 0;
    int warning = 0;
    int error = 0;

    fp = fopen("application.log", "r");

    if (fp == NULL)
    {
        printf("Log file not found\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (strstr(line, "[INFO]") != NULL)
        {
            info++;
        }
        else if (strstr(line, "[WARNING]") != NULL)
        {
            warning++;
        }
        else if (strstr(line, "[ERROR]") != NULL)
        {
            error++;
        }
    }

    fclose(fp);

    printf("Log Analysis Report\n");
    printf("-------------------\n");
    printf("INFO    : %d\n", info);
    printf("WARNING : %d\n", warning);
    printf("ERROR   : %d\n", error);

    return 0;
}
