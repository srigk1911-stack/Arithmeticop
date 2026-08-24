//C program to count the number of words in a sentence using a user-defined
#include <stdio.h>

int wordCount(char str[])
{
    int i, count = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && str[i] != '\n' &&
            (i == 0 || str[i - 1] == ' '))
        {
            count++;
        }
    }

    return count;
}

int main()
{
    char str[200];

    fgets(str, sizeof(str), stdin);

    printf("%d", wordCount(str));

    return 0;
}
