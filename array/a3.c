// Average of array
#include <stdio.h>

int main()
{
    int a[100], n, i, sum = 0;
    float avg;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum = sum + a[i];
    }

    avg = (float)sum / n;

    printf("%.2f", avg);

    return 0;
}
