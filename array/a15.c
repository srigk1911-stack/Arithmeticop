// sum even and odd
#include <stdio.h>

int main()
{
    int a[100], n, i;
    int even = 0, odd = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);

        if(a[i] % 2 == 0)
            even = even + a[i];
        else
            odd = odd + a[i];
    }

    printf("%d\n", even);
    printf("%d", odd);

    return 0;
}
