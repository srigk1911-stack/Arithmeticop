//product details
#include <stdio.h>

struct Product
{
    int id;
    char name[50];
    float cost;
};

int main()
{
    struct Product product;

    scanf("%d", &product.id);
    scanf("%s", product.name);
    scanf("%f", &product.cost);

    printf("%d\n", product.id);
    printf("%s\n", product.name);
    printf("%.2f\n", product.cost);

    return 0;
}
