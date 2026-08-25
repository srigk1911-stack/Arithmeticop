#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
 int fd;

 char buffer[100];
 
 fd=open("/tmp/myfifo",O_RDONLY);
 if(fd==-1)
 {
 perror("open");
 return 1;
 }
 read(fd,buffer,sizeof(buffer));
 printf("Reader received:%s\n",buffer);
 close(fd);
 return 0;
 }   
