//area of rectangle
#include <stdio.h>

struct Rectangle
{
    float length;
    float breadth;
};

int main()
{
    struct Rectangle r;
    float area;

    scanf("%f", &r.length);
    scanf("%f", &r.breadth);

    area = r.length * r.breadth;

    printf("%.2f", area);

    return 0;
}
