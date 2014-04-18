#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

# define SIZE 20


main()
{
	
  key_t key;
  key=5479;
  int shmid;
  char *shm,*s;

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

	s=shm;	
         
        for(s=shm;*s!='\0';s++)
	{
	printf("%c",*s);
	}
	
	exit(0);

}
