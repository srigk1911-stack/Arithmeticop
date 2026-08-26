// thread + pthread_join()

#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    printf("Thread is running\n");
    printf("Thread is completed\n");

    return NULL;
}

int main()
{
    pthread_t thread;

    pthread_create(&thread, NULL, thread_function, NULL);

    pthread_join(thread, NULL);

    printf("Main thread continues after child thread completes\n");

    return 0;
}
