#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char *str;
    int fd;

    str = malloc(100 * sizeof(char));

    if (str == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    mkfifo("/tmp/myfifo", 0666);

    fd = open("/tmp/myfifo", O_WRONLY);

    write(fd, str, strlen(str) + 1);

    close(fd);

    free(str);

    return 0;
}
