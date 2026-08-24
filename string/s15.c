//check given character exist
#include <stdio.h>

int main()
{
    char str[100], ch;
    int i, flag = 0;

    scanf("%s", str);
    scanf(" %c", &ch);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ch)
        {
            flag = 1;
            break;
        }
    }

    if (flag)
        printf("Found");
    else
        printf("Not Found");

    return 0;
}
