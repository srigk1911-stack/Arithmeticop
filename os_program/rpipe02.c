#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

int main()
{
    char *str;
    int fd;
    int vowels = 0;
    int consonants = 0;
    int digits = 0;
    int spaces = 0;

    str = malloc(100 * sizeof(char));

    if (str == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    fd = open("/tmp/myfifo", O_RDONLY);

    read(fd, str, 100);

    close(fd);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' ||
            str[i] == 'i' || str[i] == 'o' ||
            str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' ||
            str[i] == 'I' || str[i] == 'O' ||
            str[i] == 'U')
        {
            vowels++;
        }
        else if ((str[i] >= 'a' && str[i] <= 'z') ||
                 (str[i] >= 'A' && str[i] <= 'Z'))
        {
            consonants++;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            digits++;
        }
        else if (str[i] == ' ')
        {
            spaces++;
        }
    }

    printf("\nVowels = %d\n", vowels);
    printf("Consonants = %d\n", consonants);
    printf("Digits = %d\n", digits);
    printf("Spaces = %d\n", spaces);

    free(str);

    unlink("/tmp/myfifo");

    return 0;
}
