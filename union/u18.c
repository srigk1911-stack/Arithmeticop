//program to demonstrate that writing to one member of a union changes the data seen through the other members. Explain the observed output

#include <stdio.h>

union Data
{
    int i;
    float f;
};

int main()
{
    union Data data;

    data.i = 100;
    printf("%d\n", data.i);

    data.f = 25.5;
    printf("%.2f\n", data.f);

    printf("%d\n", data.i);

    return 0;
}
