// array of 5 integers

#include <stdio.h>
#include <pthread.h>

void *print_element(void *arg)
{
    int value = *(int *)arg;

    printf("Array element = %d\n", value);

    return NULL;
}

int main()
{
    pthread_t threads[5];

    int array[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++)
    {
        pthread_create(&threads[i],
                       NULL,
                       print_element,
                       &array[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
