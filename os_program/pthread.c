#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void* task(void* arg){
int id=*(int*)arg;
printf("thread %d",id);
//sleep(1);
return NULL;
}
int main ()
{

   pthread_t tid;
   pthread_create(&tid,NULL,task,&tid);
   pthread_join(tid,NULL);
   printf("All threads\n");
   return 0;
   }
