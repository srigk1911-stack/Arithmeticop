//largest and smallest 
#include <stdio.h>

int main()
{
    int a[100], n, i, largest, smallest;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    largest = a[0];
    smallest = a[0];

    for(i = 1; i < n; i++)
    {
        if(a[i] > largest)
            largest = a[i];

        if(a[i] < smallest)
            smallest = a[i];
    }

    printf("%d\n", largest);
    printf("%d", smallest);

    return 0;
}
