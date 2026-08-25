//efine a union inside a structure. Store employee ID in the structure and either salary (float) or grade (char) in the union. Display the stored information

#include <stdio.h>

struct Employee
{
    int id;

    union
    {
        float salary;
        char grade;
    } data;
};

int main()
{
    struct Employee e;
    int choice;

    scanf("%d", &e.id);
    scanf("%d", &choice);

    if (choice == 1)
    {
        scanf("%f", &e.data.salary);
        printf("%d\n", e.id);
        printf("%.2f", e.data.salary);
    }
    else
    {
        scanf(" %c", &e.data.grade);
        printf("%d\n", e.id);
        printf("%c", e.data.grade);
    }

    return 0;
}
