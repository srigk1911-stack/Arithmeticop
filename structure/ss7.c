//coordinate distnces
#include <stdio.h>
#include <math.h>

struct Point
{
    float x;
    float y;
};

int main()
{
    struct Point p;
    float distance;

    scanf("%f", &p.x);
    scanf("%f", &p.y);

    distance = sqrt(p.x * p.x + p.y * p.y);

    printf("%.2f", distance);

    return 0;
}
