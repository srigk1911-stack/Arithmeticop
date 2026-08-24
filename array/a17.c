// second largest
#include <stdio.h>

int main()
{
    int a[100], n, i, largest, second;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if(a[0] > a[1])
    {
        largest = a[0];
        second = a[1];
    }
    else
    {
        largest = a[1];
        second = a[0];
    }

    for(i = 2; i < n; i++)
    {
        if(a[i] > largest)
        {
            second = largest;
            largest = a[i];
        }
        else if(a[i] > second)
        {
            second = a[i];
        }
    }

    printf("%d", second);

    return 0;
}
