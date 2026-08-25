#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int n;
    int *marks;
    int fd[2];
    pid_t pid;

    printf("Enter number of students: ");
    scanf("%d", &n);

    marks = malloc(n * sizeof(int));

    if (marks == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter marks:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &marks[i]);
    }

    if (pipe(fd) == -1)
    {
        printf("Pipe creation failed\n");
        free(marks);
        return 1;
    }

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
        free(marks);
        return 1;
    }

    if (pid > 0)
    {
        // Parent process

        close(fd[0]);

        write(fd[1], marks, n * sizeof(int));

        close(fd[1]);

        free(marks);
    }
    else
    {
        // Child process

        int *received_marks;
        int sum = 0;
        int max;
        int min;
        float average;

        received_marks = malloc(n * sizeof(int));

        if (received_marks == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }

        close(fd[1]);

        read(fd[0], received_marks, n * sizeof(int));

        close(fd[0]);

        max = received_marks[0];
        min = received_marks[0];

        for (int i = 0; i < n; i++)
        {
            sum = sum + received_marks[i];

            if (received_marks[i] > max)
            {
                max = received_marks[i];
            }

            if (received_marks[i] < min)
            {
                min = received_marks[i];
            }
        }

        average = (float)sum / n;

        printf("\nChild Process\n");
        printf("Average = %.2f\n", average);
        printf("Maximum = %d\n", max);
        printf("Minimum = %d\n", min);

        free(received_marks);
    }

    return 0;
}
