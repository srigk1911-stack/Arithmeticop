// reomove duplicate character
#include <stdio.h>

int main()
{
    char str[100];
    int i, j, k = 0, found;

    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        found = 0;

        for (j = 0; j < k; j++)
        {
            if (str[i] == str[j])
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            str[k] = str[i];
            k++;
        }
    }

    str[k] = '\0';

    printf("%s", str);

    return 0;
}
