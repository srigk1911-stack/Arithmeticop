// count the frequency
#include <stdio.h>

int main()
{
    char str[200];
    int count[26] = {0};
    int i;

    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            count[str[i] - 'a']++;

        else if (str[i] >= 'A' && str[i] <= 'Z')
            count[str[i] - 'A']++;
    }

    for (i = 0; i < 26; i++)
    {
        if (count[i] > 0)
        {
            printf("%c %d\n", i + 'a', count[i]);
        }
    }

    return 0;
}
