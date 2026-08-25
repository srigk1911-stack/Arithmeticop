#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int n;
    int *arr;
    int fd;
    int sum = 0;
    int even = 0;
    int odd = 0;
    float average;

    fd = open("/tmp/number_fifo", O_RDONLY);

    if (fd == -1)
    {
        printf("FIFO open failed\n");
        return 1;
    }

    read(fd, &n, sizeof(int));

    arr = malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        close(fd);
        return 1;
    }

    read(fd, arr, n * sizeof(int));

    close(fd);

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];

        if (arr[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }

    average = (float)sum / n;

    printf("\nConsumer Result\n");
    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);
    printf("Even numbers = %d\n", even);
    printf("Odd numbers = %d\n", odd);

    free(arr);

    unlink("/tmp/number_fifo");

    return 0;
}
