// replace occurance
#include <stdio.h>

int main()
{
    char str[200], oldChar, newChar;
    int i;

    fgets(str, sizeof(str), stdin);
    scanf("%c %c", &oldChar, &newChar);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == oldChar)
        {
            str[i] = newChar;
        }
    }

    printf("%s", str);

    return 0;
}
