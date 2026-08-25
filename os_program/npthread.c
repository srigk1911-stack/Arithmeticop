#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void* task(void* arg){
int id=*(int*)arg;
for(int i=1;i<=3;i++)
{
printf("thread %d\n",id);
}
//sleep(1);
return NULL;
}
int main ()
{

   pthread_t tid[3];
   int id[3]={1,2,3};
   for(int i=0;i<3;i++)
   {
   pthread_create(&tid[i],NULL, task, &tid[i]);
   }
   for(int i=0;i<3;i++)
   {
   pthread_join(tid[i], NULL);
   }
   printf("All threads\n");
   return 0;
   }
   
   
   
   
   
   
   
   


