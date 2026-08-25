// union containing integer and a character array

#include <stdio.h>

union Data
{
    int i;
    char ch[sizeof(int)];
};

int main()
{
    union Data data;
    int j;

    data.i = 65;

    for (j = 0; j < sizeof(int); j++)
    {
        printf("%d ", data.ch[j]);
    }

    return 0;
}
