//book details
#include <stdio.h>

struct Book
{
    char title[100];
    char author[50];
    float price;
};

int main()
{
    struct Book book;

    scanf("%s", book.title);
    scanf("%s", book.author);
    scanf("%f", &book.price);

    printf("%s\n", book.title);
    printf("%s\n", book.author);
    printf("%.2f\n", book.price);

    return 0;
}
