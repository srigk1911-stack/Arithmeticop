//Two threads modify a shared variable count. Identify the critical section and explain why mutual exclusion is required.

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int count = 0;
sem_t mutex;

void *increment(void *arg)
{
    for (int i = 0; i < 1000; i++)
    {
        sem_wait(&mutex);

        count++;              // Critical Section

        sem_post(&mutex);
    }

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    sem_init(&mutex, 0, 1);

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final count = %d\n", count);

    sem_destroy(&mutex);

    return 0;
}
