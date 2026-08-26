// sum 1 to 10
#include <stdio.h>
#include <pthread.h>

void *calculate_sum(void *arg)
{
    int sum = 0;

    for (int i = 1; i <= 10; i++)
    {
        sum += i;
    }

    printf("Sum = %d\n", sum);

    return NULL;
}

int main()
{
    pthread_t thread;

    pthread_create(&thread, NULL, calculate_sum, NULL);

    pthread_join(thread, NULL);

    return 0;
}
