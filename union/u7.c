//menu driven that allows user to enter either an integer ,float


#include <stdio.h>

union Data
{
    int i;
    float f;
    char ch;
};

int main()
{
    union Data data;
    int choice;

    scanf("%d", &choice);

    if (choice == 1)
    {
        scanf("%d", &data.i);
        printf("%d", data.i);
    }
    else if (choice == 2)
    {
        scanf("%f", &data.f);
        printf("%.2f", data.f);
    }
    else if (choice == 3)
    {
        scanf(" %c", &data.ch);
        printf("%c", data.ch);
    }

    return 0;
}
