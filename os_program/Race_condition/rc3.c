//3 balance
#include <stdio.h>
#include <pthread.h>

int balance = 1000;

void *deposit(void *arg)
{
    balance = balance + 100;
    return NULL;
}

void *withdraw(void *arg)
{
    balance = balance - 50;
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, deposit, NULL);
    pthread_create(&t2, NULL, withdraw, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final balance = %d\n", balance);

    return 0;
}
