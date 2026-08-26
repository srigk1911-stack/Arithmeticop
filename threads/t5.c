// stringg 


#include <stdio.h>
#include <pthread.h>

void *print_name(void *arg)
{
    char *name = (char *)arg;

    printf("Hello %s\n", name);

    return NULL;
}

int main()
{
    pthread_t thread;

    char name[] = "Sripadhmapriya";

    pthread_create(&thread, NULL, print_name, name);

    pthread_join(thread, NULL);

    return 0;
}
