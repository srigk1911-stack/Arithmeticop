// 5 threads using loop


#include <stdio.h>
#include <pthread.h>

void *print_number(void *arg)
{
    int number = *(int *)arg;

    printf("Thread %d\n", number);

    return NULL;
}

int main()
{
    pthread_t threads[5];
    int numbers[5];

    for (int i = 0; i < 5; i++)
    {
        numbers[i] = i + 1;

        pthread_create(&threads[i],
                       NULL,
                       print_number,
                       &numbers[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
