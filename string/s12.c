// compare without stcmp
#include <stdio.h>

int main()
{
    char str1[100], str2[100];
    int i = 0, flag = 1;

    scanf("%s", str1);
    scanf("%s", str2);

    while (str1[i] != '\0' || str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            flag = 0;
            break;
        }
        i++;
    }

    if (flag)
        printf("Identical");
    else
        printf("Not Identical");

    return 0;
}
