//student marks
#include <stdio.h>

struct Student
{
    int mark1;
    int mark2;
    int mark3;
};

int totalMarks(struct Student s)
{
    return s.mark1 + s.mark2 + s.mark3;
}

int main()
{
    struct Student s;

    scanf("%d", &s.mark1);
    scanf("%d", &s.mark2);
    scanf("%d", &s.mark3);

    printf("%d", totalMarks(s));

    return 0;
}
