#include<sys/types.h>
#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#define SIZE 27 //this is the size of the buffer
main()
{
	key_t key;
	int shmid;
	char *shm,*s;
	int ded;
	key=5678; //5678 is the name of the segment
	if((shmid=shmget(key,SIZE,0666))<0)
	{
	    perror("Error in shmget");
	    printf("Error in shmget");
	    exit(0);
	}
	if((shm=shmat(shmid,NULL,0))==(char *)-1)
	{
		perror("Error in shmat");
		printf("Error in attching shared memory segemnt to the data space ");
		exit(0);
	}
	s=shm;
	printf("  %d  ",(int)*s);		
	s++;
	scanf("%d",&ded);
	*s=ded;
	s++;
	  
		

		exit(0);
	
}
