// last occurance
#include <stdio.h>

int main()
{
    char str[100], ch;
    int i, position = -1;

    scanf("%s", str);
    scanf(" %c", &ch);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ch)
        {
            position = i;
        }
    }

    printf("%d", position);

    return 0;
}
