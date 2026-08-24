// insert element
#include <stdio.h>

int main()
{
    int a[100], n, i, pos, value;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &pos);
    scanf("%d", &value);

    for(i = n; i > pos; i--)
        a[i] = a[i - 1];

    a[pos] = value;
    n++;

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
