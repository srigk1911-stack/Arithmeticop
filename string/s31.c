//palindrome using user define
#include <stdio.h>

int isPalindrome(char str[])
{
    int i, len = 0;

    while (str[len] != '\0')
    {
        len++;
    }

    for (i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    char str[100];

    scanf("%s", str);

    if (isPalindrome(str))
        printf("Palindrome");
    else
        printf("Not Palindrome");

    return 0;
}
