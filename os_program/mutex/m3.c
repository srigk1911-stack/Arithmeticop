//Two threads update a shared bank balance. Protect the balance update so that only one thread can modify it at a time.

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int balance = 1000;
sem_t mutex;

void *deposit(void *arg)
{
    sem_wait(&mutex);

    balance = balance + 500;

    sem_post(&mutex);

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    sem_init(&mutex, 0, 1);

    pthread_create(&t1, NULL, deposit, NULL);
    pthread_create(&t2, NULL, deposit, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final Balance = %d\n", balance);

    sem_destroy(&mutex);

    return 0;
}
