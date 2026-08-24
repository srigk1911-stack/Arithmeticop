//concatenate
#include <stdio.h>

int main()
{
    char first[100], last[100];
    int i, j = 0;

    scanf("%s", first);
    scanf("%s", last);

    while (first[j] != '\0')
    {
        j++;
    }

    first[j] = ' ';
    j++;

    for (i = 0; last[i] != '\0'; i++)
    {
        first[j] = last[i];
        j++;
    }

    first[j] = '\0';

    printf("%s", first);

    return 0;
}
