// print square
#include <stdio.h>
#include <pthread.h>

void *calculate_square(void *arg)
{
    int number = *(int *)arg;

    printf("Square of %d = %d\n", number, number * number);

    return NULL;
}

int main()
{
    pthread_t thread;

    int number = 5;

    pthread_create(&thread, NULL, calculate_square, &number);

    pthread_join(thread, NULL);

    return 0;
}
