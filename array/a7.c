// positive nagative and zero
#include <stdio.h>

int main()
{
    int a[100], n, i;
    int positive = 0, negative = 0, zero = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);

        if(a[i] > 0)
            positive++;
        else if(a[i] < 0)
            negative++;
        else
            zero++;
    }

    printf("%d\n", positive);
    printf("%d\n", negative);
    printf("%d", zero);

    return 0;
}
