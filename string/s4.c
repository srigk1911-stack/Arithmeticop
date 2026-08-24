// count the numbes of words
#include <stdio.h>

int main()
{
    char str[200];
    int i, words = 0;

    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && str[i] != '\n' &&
            (i == 0 || str[i - 1] == ' '))
        {
            words++;
        }
    }

    printf("%d", words);

    return 0;
}
