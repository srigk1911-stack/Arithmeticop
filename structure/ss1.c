//students details
#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    float marks;
};

int main()
{
    struct Student sripadhmapriya;

    scanf("%d", &sripadhmapriya.roll);
    scanf("%s", sripadhmapriya.name);
    scanf("%f", &sripadhmapriya.marks);

    printf("%d\n", sripadhmapriya.roll);
    printf("%s\n", sripadhmapriya.name);
    printf("%.2f\n", sripadhmapriya.marks);

    return 0;
}
