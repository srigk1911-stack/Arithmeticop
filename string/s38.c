//TOGLE 
#include <stdio.h>

void toggleCase(char str[])
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
}

int main()
{
    char str[100];

    scanf("%s", str);

    toggleCase(str);

    printf("%s", str);

    return 0;
}
