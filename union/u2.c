//Write a program to determine the size of a union containing char, int, float, and double. Explain why the size is equal to its largest member

#include <stdio.h>

union Data
{
    char ch;
    int i;
    float f;
    double d;
};

int main()
{
    union Data data;

    printf("%lu\n", sizeof(data));
    printf("%lu\n", sizeof(data.ch));
    printf("%lu\n", sizeof(data.i));
    printf("%lu\n", sizeof(data.f));
    printf("%lu\n", sizeof(data.d));

    return 0;
}
