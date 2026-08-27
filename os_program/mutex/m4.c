//Implement mutual exclusion using a POSIX semaphore initialized to 1. Explain how it prevents two threads from entering the critical section simultaneously.

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex;

void *task(void *arg)
{
    sem_wait(&mutex);

    printf("Thread %ld entered critical section\n", (long)pthread_self());

    printf("Thread %ld is accessing shared resource\n", (long)pthread_self());

    sem_post(&mutex);

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    sem_init(&mutex, 0, 1);

    pthread_create(&t1, NULL, task, NULL);
    pthread_create(&t2, NULL, task, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&mutex);

    return 0;
}
