//occurance
#include <stdio.h>

void replaceCharacter(char str[], char oldChar, char newChar)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == oldChar)
            str[i] = newChar;
    }
}

int main()
{
    char str[100], oldChar, newChar;

    scanf("%s", str);
    scanf(" %c %c", &oldChar, &newChar);

    replaceCharacter(str, oldChar, newChar);

    printf("%s", str);

    return 0;
}
