//Count binary file records

#include <stdio.h>

struct Employee
{
    int id;
    char name[30];
    float salary;
};

int main()
{
    FILE *fp;
    long size;
    int count;

    fp = fopen("employee.dat", "rb");

    if (fp == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);

    size = ftell(fp);

    count = size / sizeof(struct Employee);

    printf("%d", count);

    fclose(fp);

    return 0;
}
