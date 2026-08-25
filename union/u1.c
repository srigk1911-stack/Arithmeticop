//write a C program to declare a union containing an integer, a floating-point number, and a character. Assign values to each member one at a time and display the results

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

    data.i = 10;
    printf("%d\n", data.i);

    data.f = 20.5;
    printf("%.2f\n", data.f);

    data.ch = 'A';
    printf("%c\n", data.ch);

    return 0;
}
