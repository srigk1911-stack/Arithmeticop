//Dynamic union variables

#include <stdio.h>
#include <stdlib.h>

union Data
{
    int id;
    float marks;
    char name[30];
};

int main()
{
    int n, i, choice;
    union Data *data;

    scanf("%d", &n);

    data = (union Data *)malloc(n * sizeof(union Data));

    for (i = 0; i < n; i++)
    {
        scanf("%d", &choice);

        if (choice == 1)
        {
            scanf("%d", &data[i].id);
        }
        else if (choice == 2)
        {
            scanf("%f", &data[i].marks);
        }
        else
        {
            scanf("%s", data[i].name);
        }
    }

    for (i = 0; i < n; i++)
    {
        if (choice == 1)
            printf("%d\n", data[i].id);
        else if (choice == 2)
            printf("%.2f\n", data[i].marks);
        else
            printf("%s\n", data[i].name);
    }

    free(data);

    return 0;
}
