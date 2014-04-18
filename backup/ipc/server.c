#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>

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
	printf("Enter string:");
	scanf("%s",s);
	
	while(*s!='*')
	   sleep(1);
	
	exit(0);

}			
	
