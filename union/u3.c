//union with int and float


#include <stdio.h>

union Data
{
    int i;
    float f;
};

int main()
{
    union Data data;

    data.i = 10;
    printf("%d\n", data.i);

    data.f = 20.5;
    printf("%.2f\n", data.f);

    printf("%d\n", data.i);

    return 0;
}
