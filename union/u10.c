//nion with an integer and a character array. Read an integer from the user and display its individual bytes using the character array

#include <stdio.h>

union Data
{
    int i;
    unsigned char ch[sizeof(int)];
};

int main()
{
    union Data data;
    int j;

    scanf("%d", &data.i);

    for (j = 0; j < sizeof(int); j++)
    {
        printf("%u ", data.ch[j]);
    }

    return 0;
}
