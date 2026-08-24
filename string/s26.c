// finding length using the user defined function
#include <stdio.h>

int stringLength(char str[])
{
    int i = 0;

    while (str[i] != '\0')
    {
        i++;
    }

    return i;
}

int main()
{
    char str[100];

    scanf("%s", str);

    printf("%d", stringLength(str));

    return 0;
}
