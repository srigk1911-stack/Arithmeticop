//concatenate userdefined function
#include <stdio.h>

void stringConcat(char dest[], char src[])
{
    int i = 0, j = 0;

    while (dest[i] != '\0')
    {
        i++;
    }

    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0';
}

int main()
{
    char str1[200], str2[100];

    scanf("%s", str1);
    scanf("%s", str2);

    stringConcat(str1, str2);

    printf("%s", str1);

    return 0;
}
