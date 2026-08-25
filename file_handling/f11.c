//Store and retrieve structures using binary file

#include <stdio.h>

struct Student
{
    int roll;
    char name[30];
    float marks;
};

int main()
{
    FILE *fp;
    struct Student s[3], temp;
    int i;

    for (i = 0; i < 3; i++)
    {
        scanf("%d", &s[i].roll);
        scanf("%s", s[i].name);
        scanf("%f", &s[i].marks);
    }

    fp = fopen("students.dat", "wb");

    fwrite(s, sizeof(struct Student), 3, fp);

    fclose(fp);

    fp = fopen("students.dat", "rb");

    while (fread(&temp, sizeof(struct Student), 1, fp) == 1)
    {
        printf("%d %s %.2f\n", temp.roll, temp.name, temp.marks);
    }

    fclose(fp);

    return 0;
}
