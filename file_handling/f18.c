//csv

#include <stdio.h>

struct Student
{
    int roll;
    char name[30];
    float marks;
};

int main()
{
    FILE *bin, *csv;
    struct Student s;
    int count = 0;

    bin = fopen("students.dat", "wb");

    if (bin == NULL)
    {
        printf("Binary file cannot be created\n");
        return 1;
    }

    struct Student students[] =
    {
        {101, "Arun", 85.5},
        {102, "Bala", 90.0},
        {103, "Kavi", 78.5}
    };

    fwrite(students, sizeof(struct Student), 3, bin);
    fclose(bin);

    bin = fopen("students.dat", "rb");
    csv = fopen("students.csv", "w");

    if (bin == NULL || csv == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    fprintf(csv, "Roll,Name,Marks\n");

    while (fread(&s, sizeof(struct Student), 1, bin) == 1)
    {
        fprintf(csv, "%d,%s,%.2f\n",
                s.roll, s.name, s.marks);

        printf("Roll: %d  Name: %s  Marks: %.2f\n",
               s.roll, s.name, s.marks);

        count++;
    }

    fclose(bin);
    fclose(csv);

    printf("\n%d records converted to CSV successfully\n", count);

    return 0;
}
