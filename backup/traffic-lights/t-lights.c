/* This code was NOT written by Varad.
   Hence is simple.
*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include <netinet/in.h>
#include <pthread.h>
#include <unistd.h>
# define SIZE 20
void *trafficSignal(void *tid){
  int id ;
  key_t key;
  id = *((int *) tid);
  key=5479;
  int shmid;
  char *shm,*s,*t;
  char dig = (char)(((int)'0')+id);
  if((shmid=shmget(key,SIZE,IPC_CREAT |0666))<0)
    {
      printf("shmid");
      exit(0);
    }
  if((shm=shmat(shmid,NULL,0))==(char *)(-1))
    {
      printf("shmat");
      exit(0);
    }

  printf("Reached signal %d",id);
  while (1)
    {
      if ((int)*shm == (int)dig)
	{
	  printf("%d is GREEN \n",id);
	  //sleep(2);
	  dig = (char)(((int)'0')+id+1);
	  printf ("%d is RED \n",id);
	  fflush(stdout);
	  *shm = dig;
	}
    }
}

int main(){
  key_t key;
  key=5479;
  int shmid, signalCount;
  char *shm;
  pthread_t acc_thread[10];  
  if((shmid=shmget(key,SIZE,IPC_CREAT |0666))<0)
    {
      printf("shmid");
      exit(0);
    }
  if((shm=shmat(shmid,NULL,0))==(char *)(-1))
    {
      printf("shmat");
      exit(0);
    }	
  *shm='1';
  printf("How many traffic signals would you like, Varad ? :- ");
  scanf ("%d",&signalCount);
  for (int i = 0 ;i < signalCount ; i++)
    {
      if(!pthread_create(&acc_thread[i],NULL, trafficSignal,(void *) &i)){
	printf("\nNEW thread Created : %d\n",i);
       
      }
    }
  fflush(stdout);
  for(int t=0; t<signalCount; t++){
    pthread_join(acc_thread[t], NULL);
  }
  pthread_exit(NULL);
  return 0;
}
