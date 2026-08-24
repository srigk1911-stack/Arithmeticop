// even odd count
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
            even++;
        else
            odd++;
    }

    printf("%d\n", even);
    printf("%d", odd);

    return 0;
}
