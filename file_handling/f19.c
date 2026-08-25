//Generate Sales Report in CSV

#include <stdio.h>

struct Sale
{
    int id;
    char product[30];
    int quantity;
    float price;
};

int main()
{
    FILE *fp;
    struct Sale s;
    int n, i;
    float total;

    fp = fopen("sales.csv", "w");

    if (fp == NULL)
    {
        printf("File cannot be created\n");
        return 1;
    }

    scanf("%d", &n);

    fprintf(fp, "ID,Product,Quantity,Price,Total\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &s.id);
        scanf("%s", s.product);
        scanf("%d", &s.quantity);
        scanf("%f", &s.price);

        total = s.quantity * s.price;

        fprintf(fp, "%d,%s,%d,%.2f,%.2f\n",
                s.id,
                s.product,
                s.quantity,
                s.price,
                total);

        printf("ID: %d\n", s.id);
        printf("Product: %s\n", s.product);
        printf("Quantity: %d\n", s.quantity);
        printf("Price: %.2f\n", s.price);
        printf("Total: %.2f\n\n", total);
    }

    fclose(fp);

    printf("Sales report created successfully\n");

    return 0;
}
