// mobile details
#include <stdio.h>

struct Mobile
{
    char brand[50];
    char model[50];
    float price;
};

int main()
{
    struct Mobile phone;

    scanf("%s", phone.brand);
    scanf("%s", phone.model);
    scanf("%f", &phone.price);

    printf("%s\n", phone.brand);
    printf("%s\n", phone.model);
    printf("%.2f\n", phone.price);

    return 0;
}
