//union with two integer members. Assign different values to each member and explain why only the last assigned value is retained



#include <stdio.h>

union Data
{
    int a;
    int b;
};

int main()
{
    union Data data;

    data.a = 10;
    data.b = 20;

    printf("%d\n", data.a);
    printf("%d\n", data.b);

    return 0;
}
