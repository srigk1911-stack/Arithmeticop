//Update salary in binary file

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
    struct Employee e;
    int id;
    float salary;

    fp = fopen("employee.dat", "rb+");

    scanf("%d", &id);
    scanf("%f", &salary);

    while (fread(&e, sizeof(struct Employee), 1, fp) == 1)
    {
        if (e.id == id)
        {
            e.salary = salary;

            fseek(fp, -sizeof(struct Employee), SEEK_CUR);
            fwrite(&e, sizeof(struct Employee), 1, fp);

            break;
        }
    }

    fclose(fp);

    return 0;
}
