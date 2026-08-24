//C program to validate whether a password contains at least one uppercase letter, one lowercase letter, one digit, and one special character
#include <stdio.h>

int main()
{
    char str[100];
    int i;
    int upper = 0, lower = 0, digit = 0, special = 0;

    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            upper = 1;
        else if (str[i] >= 'a' && str[i] <= 'z')
            lower = 1;
        else if (str[i] >= '0' && str[i] <= '9')
            digit = 1;
        else
            special = 1;
    }

    if (upper && lower && digit && special)
        printf("Valid");
    else
        printf("Invalid");

    return 0;
}
