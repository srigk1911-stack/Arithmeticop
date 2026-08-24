// students name and displaying
#include <stdio.h>

int main()
{
    char sripadhmapriya[100];

    fgets(sripadhmapriya, sizeof(sripadhmapriya), stdin);

    printf("%s", sripadhmapriya);

    return 0;
}
