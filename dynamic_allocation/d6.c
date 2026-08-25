//Dynamically allocate memory for N strings

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    char **name;

    scanf("%d", &n);

    name = (char **)malloc(n * sizeof(char *));

    for (i = 0; i < n; i++)
    {
        name[i] = (char *)malloc(30 * sizeof(char));
        scanf("%s", name[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("%s\n", name[i]);
        free(name[i]);
    }

    free(name);

    return 0;
}
