// intializing union

#include <stdio.h>

union Data
{
    int i;
    float f;
    char ch;
};

int main()
{
    union Data data = {10};

    printf("%d\n", data.i);
    printf("%.2f\n", data.f);
    printf("%c\n", data.ch);

    return 0;
}
