// hello before world
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

void *hello(void *arg)
{
    printf("Hello\n");

    sem_post(&sem);

    return NULL;
}

void *world(void *arg)
{
    sem_wait(&sem);

    printf("World\n");

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    sem_init(&sem, 0, 0);

    pthread_create(&t2, NULL, world, NULL);
    pthread_create(&t1, NULL, hello, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&sem);

    return 0;
}
