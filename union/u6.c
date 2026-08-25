//memoey usage of structure and a union

#include <stdio.h>

struct Data1
{
    char ch;
    int i;
    float f;
};

union Data2
{
    char ch;
    int i;
    float f;
};

int main()
{
    printf("%lu\n", sizeof(struct Data1));
    printf("%lu\n", sizeof(union Data2));

    return 0;
}
