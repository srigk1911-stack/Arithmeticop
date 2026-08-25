#include<stdio.h>
struct Student
{
    char name[30];
    int roll;
    float marks;
};

// Function to write student details into file
void writeFile(struct Student s)
{
    FILE *fp;

    fp = fopen("student.txt", "w");

    if(fp == NULL)
    {
        printf("File cannot be opened.\n");
        return;
    }

    fprintf(fp, "Student Details\n");
    fprintf(fp, "---------------\n");
    fprintf(fp, "Name : %s\n", s.name);
    fprintf(fp, "Roll Number : %d\n", s.roll);
    fprintf(fp, "Marks : %.2f\n", s.marks);

    fclose(fp);

    printf("Data written successfully.\n");
}

int main()
{
    struct Student s;

    printf("Enter Name : ");
    scanf("%s", s.name);

    printf("Enter Roll Number : ");
    scanf("%d", &s.roll);

    printf("Enter Marks : ");
    scanf("%f", &s.marks);

    writeFile(s);

    return 0;
}
