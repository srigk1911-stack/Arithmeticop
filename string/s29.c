// compare two strings
#include <stdio.h>

int stringCompare(char s1[], char s2[])
{
    int i = 0;

    while (s1[i] != '\0' || s2[i] != '\0')
    {
        if (s1[i] != s2[i])
        {
            return 0;
        }

        i++;
    }

    return 1;
}

int main()
{
    char str1[100], str2[100];

    scanf("%s", str1);
    scanf("%s", str2);

    if (stringCompare(str1, str2))
        printf("Identical");
    else
        printf("Not Identical");

    return 0;
}
