//function that returns a union after assigning a value to one of its members. Display the returned value in the calling function

#include <stdio.h>

union Data
{
    int i;
    float f;
};

union Data getData()
{
    union Data data;

    data.i = 100;

    return data;
}

int main()
{
    union Data data;

    data = getData();

    printf("%d", data.i);

    return 0;
}
