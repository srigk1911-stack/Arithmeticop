// descending order
#include <stdio.h>

int main()
{
    int a[100], n, i, flag = 1;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n - 1; i++)
    {
        if(a[i] < a[i + 1])
        {
            flag = 0;
            break;
        }
    }

    if(flag == 1)
        printf("Descending");
    else
        printf("Not Descending");

    return 0;
}
