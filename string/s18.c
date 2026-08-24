// remove all digits from mixed string
#include <stdio.h>

int main()
{
    char str[100];
    int i, j = 0;

    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
        {
            str[j] = str[i];
            j++;
        }
    }

    str[j] = '\0';

    printf("%s", str);

    return 0;
}
