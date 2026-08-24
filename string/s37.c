//uppercase to lowercase
#include <stdio.h>

void toLowerCase(char str[])
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
}

int main()
{
    char str[100];

    scanf("%s", str);

    toLowerCase(str);

    printf("%s", str);

    return 0;
}
