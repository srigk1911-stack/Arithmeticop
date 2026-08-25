//function that accepts a union as an argument and displays the currently stored value.

#include <stdio.h>

union Data
{
    int i;
    float f;
};

void display(union Data data)
{
    printf("%d", data.i);
}

int main()
{
    union Data data;

    data.i = 50;

    display(data);

    return 0;
}
