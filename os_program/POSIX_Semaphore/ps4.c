// producer consumer
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int data;

sem_t empty;
sem_t full;

void *producer(void *arg)
{
    data = 100;

    printf("Producer produced: %d\n", data);

    sem_post(&full);

    return NULL;
}

void *consumer(void *arg)
{
    sem_wait(&full);

    printf("Consumer consumed: %d\n", data);

    sem_post(&empty);

    return NULL;
}

int main()
{
    pthread_t producer_thread, consumer_thread;

    sem_init(&empty, 0, 1);
    sem_init(&full, 0, 0);

    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_create(&producer_thread, NULL, producer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
