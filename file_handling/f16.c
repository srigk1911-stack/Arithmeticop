//csv
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char line[100];
    char *token;
    float marks, sum = 0;
    int count = 0;

    fp = fopen("students.csv", "w");

    if (fp == NULL)
    {
        printf("File cannot be created\n");
        return 1;
    }

    fprintf(fp, "Name,Marks\n");
    fprintf(fp, "Arun,80\n");
    fprintf(fp, "Bala,90\n");
    fprintf(fp, "Kavi,70\n");

    fclose(fp);

    fp = fopen("students.csv", "r");

    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        token = strtok(line, ",");

        token = strtok(NULL, ",");

        marks = atof(token);

        sum = sum + marks;
        count++;
    }

    fclose(fp);

    printf("Student Marks:\n");
    printf("Arun : 80\n");
    printf("Bala : 90\n");
    printf("Kavi : 70\n");

    printf("Average Marks = %.2f\n", sum / count);

    return 0;
}
