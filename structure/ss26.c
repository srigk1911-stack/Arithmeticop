//C program to store bank account information and calculate annual interest

#include <stdio.h>

struct Account
{
    int number;
    char name[50];
    float balance;
    float rate;
};

int main()
{
    struct Account a;
    float interest;

    scanf("%d", &a.number);
    scanf("%s", a.name);
    scanf("%f", &a.balance);
    scanf("%f", &a.rate);

    interest = (a.balance * a.rate) / 100;

    printf("%.2f", interest);

    return 0;
}
