#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main()
{
 int fd;
    pid_t pid;

    char *msg = "Hello through FIFO";
    //open FIFO for writing
    fd=open("/tmp/myfifo",O_WRONLY);
    if(fd==-1)
    {
    perror("open");
    return 1;
    }
    
    write(fd,msg,strlen(msg)+1);
    close(fd);
    return 0;
    } 
