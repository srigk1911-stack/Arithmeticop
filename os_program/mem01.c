#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SHM_NAME "/my_shm"
#define SIZE 1024

int main() {
    int fd;
    char *ptr;

    // Create or open shared memory object
    fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);

    if (fd == -1) {
        perror("shm_open");
        return 1;
    }

    // Set size
    if (ftruncate(fd, SIZE) == -1) {
        perror("ftruncate");
        return 1;
    }

    // Map shared memory
    ptr = mmap(NULL, SIZE, PROT_READ | PROT_WRITE,
               MAP_SHARED, fd, 0);

    if (ptr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Write data
    strcpy(ptr, "Hello from Producer Process!");

    printf("Producer has written the message.\n");

    // Cleanup
    munmap(ptr, SIZE);
    close(fd);

    return 0;
}
