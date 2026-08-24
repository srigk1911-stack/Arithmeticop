//multiply by user given value
#include <stdio.h>

int main()
{
    int a[100], n, i, k;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &k);

    for(i = 0; i < n; i++)
    {
        a[i] = a[i] * k;
        printf("%d ", a[i]);
    }

    return 0;
}
