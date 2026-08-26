//single thread
#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    printf("Hello from Thread\n");
    return NULL;
}

int main()
{
    pthread_t thread;

    pthread_create(&thread, NULL, thread_function, NULL);

    pthread_join(thread, NULL);

    return 0;
}
