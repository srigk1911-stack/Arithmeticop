//Array of structures + dynamic name

#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int roll_no;
    char *name;
    float marks;
};

int main()
{
    int n, i;
    struct Student *s;

    scanf("%d", &n);

    s = malloc(n * sizeof(struct Student));

    for (i = 0; i < n; i++)
    {
        s[i].name = malloc(30 * sizeof(char));

        scanf("%d", &s[i].roll_no);
        scanf("%s", s[i].name);
        scanf("%f", &s[i].marks);
    }

    for (i = 0; i < n; i++)
    {
        printf("%d %s %.2f\n", s[i].roll_no, s[i].name, s[i].marks);
        free(s[i].name);
    }

    free(s);

    return 0;
}
