//anagrams
#include <stdio.h>

int main()
{
    char str1[100], str2[100];
    int count1[26] = {0}, count2[26] = {0};
    int i, flag = 1;

    scanf("%s", str1);
    scanf("%s", str2);

    for (i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] >= 'a' && str1[i] <= 'z')
            count1[str1[i] - 'a']++;
    }

    for (i = 0; str2[i] != '\0'; i++)
    {
        if (str2[i] >= 'a' && str2[i] <= 'z')
            count2[str2[i] - 'a']++;
    }

    for (i = 0; i < 26; i++)
    {
        if (count1[i] != count2[i])
        {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("Anagram");
    else
        printf("Not Anagram");

    return 0;
}
