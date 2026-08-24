// linear search
#include <stdio.h>

int main()
{
    int a[100], n, i, key, found = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &key);

    for(i = 0; i < n; i++)
    {
        if(a[i] == key)
        {
            printf("%d", i);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("-1");

    return 0;
}
