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
  char *shm,*s,*t;

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
	
	*shm='0';
	s=shm;
	t=shm;

	while(*s=='0')
	{
	s++;
	printf("Enter Char:");
	scanf("%c",s);
	*t='1';
	while(*t!='0')
	 sleep(1);
	s=shm;
	}
	
	exit(0);

}			
	
