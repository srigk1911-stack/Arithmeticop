// copy using user defined function
#include <stdio.h>

void stringCopy(char dest[], char src[])
{
    int i;

    for (i = 0; src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }

    dest[i] = '\0';
}

int main()
{
    char str1[100], str2[100];

    scanf("%s", str1);

    stringCopy(str2, str1);

    printf("%s", str2);

    return 0;
}

