//C program to count the number of digits, alphabets, and special characters using separate user-defined functions
#include <stdio.h>

int countDigits(char str[])
{
    int i, count = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            count++;
    }

    return count;
}

int countAlphabets(char str[])
{
    int i, count = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z'))
            count++;
    }

    return count;
}

int countSpecial(char str[])
{
    int i, count = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (!((str[i] >= 'a' && str[i] <= 'z') ||
              (str[i] >= 'A' && str[i] <= 'Z') ||
              (str[i] >= '0' && str[i] <= '9') ||
              str[i] == ' ' || str[i] == '\n'))
            count++;
    }

    return count;
}

int main()
{
    char str[200];

    fgets(str, sizeof(str), stdin);

    printf("%d %d %d", countDigits(str), countAlphabets(str), countSpecial(str));

    return 0;
}
