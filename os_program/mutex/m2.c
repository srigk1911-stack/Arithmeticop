//Write a program where two threads print numbers from 1 to 10 using a shared output resource. Ensure that only one thread prints at a time.
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex;

void *printNumbers(void *arg)
{
    sem_wait(&mutex);

    for (int i = 1; i <= 10; i++)
    {
        printf("%d ", i);
    }

    printf("\n");

    sem_post(&mutex);

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    sem_init(&mutex, 0, 1);

    pthread_create(&t1, NULL, printNumbers, NULL);
    pthread_create(&t2, NULL, printNumbers, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&mutex);

    return 0;
}
