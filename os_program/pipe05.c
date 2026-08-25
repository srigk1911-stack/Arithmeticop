#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int n;
    int *arr;
    int fd;

    printf("Enter number of integers: ");
    scanf("%d", &n);

    arr = malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    if (mkfifo("/tmp/number_fifo", 0666) == -1)
    {
        /* FIFO may already exist */
    }

    fd = open("/tmp/number_fifo", O_WRONLY);

    if (fd == -1)
    {
        printf("FIFO open failed\n");
        free(arr);
        return 1;
    }

    write(fd, &n, sizeof(int));

    write(fd, arr, n * sizeof(int));

    close(fd);

    free(arr);

    return 0;
}
