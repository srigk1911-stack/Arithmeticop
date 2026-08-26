// three threads and different task
#include <stdio.h>
#include <pthread.h>

void *print_numbers(void *arg)
{
    for (int i = 1; i <= 5; i++)
    {
        printf("Number: %d\n", i);
    }

    return NULL;
}

void *print_alphabets(void *arg)
{
    for (char c = 'A'; c <= 'E'; c++)
    {
        printf("Alphabet: %c\n", c);
    }

    return NULL;
}

void *print_message(void *arg)
{
    printf("Hello from Message Thread\n");

    return NULL;
}

int main()
{
    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, print_numbers, NULL);
    pthread_create(&t2, NULL, print_alphabets, NULL);
    pthread_create(&t3, NULL, print_message, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}
