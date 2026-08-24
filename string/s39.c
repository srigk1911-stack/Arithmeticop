// frequency o a given character
#include <stdio.h>

int charFrequency(char str[], char ch)
{
    int i, count = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ch)
            count++;
    }

    return count;
}

int main()
{
    char str[100], ch;

    scanf("%s", str);
    scanf(" %c", &ch);

    printf("%d", charFrequency(str, ch));

    return 0;
}
