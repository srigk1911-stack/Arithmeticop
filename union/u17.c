#include <stdio.h>

union Data
{
    struct
    {
        int a;
        int b;
    } s;

    int x;
};

int main()
{
    union Data data;

    data.s.a = 10;
    data.s.b = 20;

    printf("%d %d\n", data.s.a, data.s.b);

    data.x = 50;

    printf("%d %d\n", data.s.a, data.s.b);

    return 0;
}
