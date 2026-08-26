// 10 threads + print thraed ID +join
#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    printf("Thread ID: %lu\n", (unsigned long)pthread_self());

    return NULL;
}

int main()
{
    pthread_t threads[10];

    for (int i = 0; i < 10; i++)
    {
        pthread_create(&threads[i], NULL, thread_function, NULL);
    }

    for (int i = 0; i < 10; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
