#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    int fd[2];
    pid_t pid;

    char message[] = "Hello from parent";
    char buffer[100];

    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(1);
    }

    pid = fork();

    if (pid == 0)
    {
        // Child

        close(fd[1]);

        read(fd[0], buffer, sizeof(buffer));

        printf("Child received: %s\n", buffer);

        close(fd[0]);

        exit(0);
    }
    else
    {
        // Parent

        close(fd[0]);

        write(fd[1], message, strlen(message) + 1);

        close(fd[1]);

        wait(NULL);

        printf("Parent process completed\n");
    }

    return 0;
}
