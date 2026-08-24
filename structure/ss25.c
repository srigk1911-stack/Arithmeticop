//Write a C program to implement a library book record containing Book ID, Name, Author, Copies Available, and display all details

#include <stdio.h>

struct Book
{
    int id;
    char name[50];
    char author[50];
    int copies;
};

int main()
{
    struct Book book;

    scanf("%d", &book.id);
    scanf("%s", book.name);
    scanf("%s", book.author);
    scanf("%d", &book.copies);

    printf("%d\n", book.id);
    printf("%s\n", book.name);
    printf("%s\n", book.author);
    printf("%d\n", book.copies);

    return 0;
}
