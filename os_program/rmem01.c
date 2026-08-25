// Program for Shared Memory - Consumer

#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SHM_NAME "/my_shm"
#define SIZE 1024

int main()
{
    int fd;
    char *ptr;

    // Open existing shared memory
    fd = shm_open(SHM_NAME, O_RDONLY, 0666);

    if (fd == -1)
    {
        perror("shm_open");
        return 1;
    }

    // Map shared memory
    ptr = mmap(NULL, SIZE, PROT_READ, MAP_SHARED, fd, 0);

    if (ptr == MAP_FAILED)
    {
        perror("mmap");
        close(fd);
        return 1;
    }

    // Read data
    printf("Consumer received: %s\n", ptr);

    // Cleanup
    munmap(ptr, SIZE);
    close(fd);

    return 0;
}
