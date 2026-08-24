// remove all repeated consectuive 
#include <stdio.h>

int main()
{
    char str[100];
    int i, j = 0;

    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (i == 0 || str[i] != str[i - 1])
        {
            str[j] = str[i];
            j++;
        }
    }

    str[j] = '\0';

    printf("%s", str);

    return 0;
}
