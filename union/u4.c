//memory adddress

#include <stdio.h>

union Data
{
    int i;
    float f;
    char ch;
};

int main()
{
    union Data data;

    printf("%p\n", (void *)&data.i);
    printf("%p\n", (void *)&data.f);
    printf("%p\n", (void *)&data.ch);

    return 0;
}
