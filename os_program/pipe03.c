#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int n;
    int *arr;
    int *sorted_arr;
    int fd1[2];
    int fd2[2];
    pid_t pid;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    if (pipe(fd1) == -1)
    {
        printf("First pipe creation failed\n");
        free(arr);
        return 1;
    }

    if (pipe(fd2) == -1)
    {
        printf("Second pipe creation failed\n");
        free(arr);
        return 1;
    }

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
        free(arr);
        return 1;
    }

    if (pid > 0)
    {
        // Parent

        close(fd1[0]);
        close(fd2[1]);

        write(fd1[1], arr, n * sizeof(int));

        close(fd1[1]);

        sorted_arr = malloc(n * sizeof(int));

        if (sorted_arr == NULL)
        {
            printf("Memory allocation failed\n");
            free(arr);
            return 1;
        }

        read(fd2[0], sorted_arr, n * sizeof(int));

        close(fd2[0]);

        printf("\nSorted array:\n");

        for (int i = 0; i < n; i++)
        {
            printf("%d ", sorted_arr[i]);
        }

        printf("\n");

        free(arr);
        free(sorted_arr);
    }
    else
    {
        // Child

        close(fd1[1]);
        close(fd2[0]);

        sorted_arr = malloc(n * sizeof(int));

        if (sorted_arr == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }

        read(fd1[0], sorted_arr, n * sizeof(int));

        close(fd1[0]);

        // Sorting
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (sorted_arr[j] > sorted_arr[j + 1])
                {
                    int temp = sorted_arr[j];

                    sorted_arr[j] = sorted_arr[j + 1];

                    sorted_arr[j + 1] = temp;
                }
            }
        }

        write(fd2[1], sorted_arr, n * sizeof(int));

        close(fd2[1]);

        free(sorted_arr);
    }

    return 0;
}
