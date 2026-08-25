/*#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int x=2;
void*routine()
{
x+=5;
sleep(2);
printf("value of x:%d\n",x);
}

void*routine2()
{
x+=5;
sleep(2);
printf("value of x:%d\n",x);
}

int main(int argc,char*argv[])
{
pthread_t t1,t2;
if(pthread_create(&t1,NULL,&routine , NULL){
return 1;
}

if(pthread_create(&t1,NULL,&routine2, NULL){
return 2;
}
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int x = 2;

void *routine(void *arg)
{
    x += 5;
    sleep(2);
    printf("value of x: %d\n", x);

    return NULL;
}

void *routine2(void *arg)
{
    x += 5;
    sleep(2);
    printf("value of x: %d\n", x);

    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t t1, t2;

    if (pthread_create(&t1, NULL, routine, NULL) != 0)
    {
        return 1;
    }

    if (pthread_create(&t2, NULL, routine2, NULL) != 0)
    {
        return 2;
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final value of x: %d\n", x);

    return 0;
}

