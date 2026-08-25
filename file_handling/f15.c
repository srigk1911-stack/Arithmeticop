//Sort Employee Records in Binary File


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
    struct Employee e[50], temp;
    int n = 0;
    int i, j;

    fp = fopen("employee.dat", "rb");

    if (fp == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    while (fread(&e[n], sizeof(struct Employee), 1, fp) == 1)
    {
        n++;
    }

    fclose(fp);

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (e[i].id > e[j].id)
            {
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }

    fp = fopen("employee.dat", "wb");

    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    fwrite(e, sizeof(struct Employee), n, fp);

    fclose(fp);

    printf("Records sorted successfully\n");

    return 0;
}
