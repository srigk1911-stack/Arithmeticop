// lower case to upper case
#include <stdio.h>

void toUpperCase(char str[])
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
}

int main()
{
    char str[100];

    scanf("%s", str);

    toUpperCase(str);

    printf("%s", str);

    return 0;
}
