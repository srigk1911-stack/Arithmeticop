//union with short, int, and long. Print the size of each member and the overall size of the union

#include <stdio.h>

union Data
{
    short s;
    int i;
    long l;
};

int main()
{
    union Data data;

    printf("%lu\n", sizeof(data.s));
    printf("%lu\n", sizeof(data.i));
    printf("%lu\n", sizeof(data.l));
    printf("%lu\n", sizeof(data));

    return 0;
}
