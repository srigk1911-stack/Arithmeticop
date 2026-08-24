//consonants
#include <stdio.h>

int countConsonants(char str[])
{
    int i, count = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z'))
        {
            if (!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
                  str[i] == 'o' || str[i] == 'u' ||
                  str[i] == 'A' || str[i] == 'E' || str[i] == 'I' ||
                  str[i] == 'O' || str[i] == 'U'))
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    char str[100];

    scanf("%s", str);

    printf("%d", countConsonants(str));

    return 0;
}
