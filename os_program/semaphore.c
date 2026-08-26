#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t semaphore;

void *thread_function(void *arg)
{
    int id = *(int *)arg;

    for (int i = 0; i < 3; i++)
    {
        sem_wait(&semaphore);

        printf("Thread %d entering critical section\n", id);
        sleep(1);
        printf("Thread %d leaving critical section\n", id);

        sem_post(&semaphore);

        sleep(1);
    }

    return NULL;
}

int main()
{
    pthread_t t1, t2;
    int id1 = 1;
    int id2 = 2;

    sem_init(&semaphore, 0, 1);

    pthread_create(&t1, NULL, thread_function, &id1);
    pthread_create(&t2, NULL, thread_function, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&semaphore);

    return 0;
}
