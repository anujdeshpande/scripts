// 
// Traffic signal simulation using shared memory 
// Varad Kulkarni
//
// Compile with 'gcc -o sig sig.c'
// Run multiple instances of this program in different terminals
//
// For the first instance start with './sig first'
//  rest of the instaces start with './sig'
//  You can create max 255 signals :D
//
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

# define SIZE 2

main(int argc,char *argv[])
{

  key_t key;
  key=5479;
  int shmid,temp;
  char *shm,*s,self;

  if((shmid=shmget(key,SIZE,IPC_CREAT |0666))<0) // create shared memory
  {
    printf("shmid");
    return -1;
  }

 if(((shm=shmat(shmid,NULL,0))==(char *)(-1))) // attach to shared memory
	{
	printf("shmat");
	return -1;
	}

	s=shm; // first byte of shm i.e. *(s) indicates which signal is currently GREEN
			// second byte of shm i.e. *(s+1) indicates total number of signals

	if (argc>1) // './sig first' is found
	{ 
		*(s+1)=-1;
		*s=0;
	}

	self=(*(s+1))+1;
	(*(s+1))=self;

	printf ("\n Signal created with ID %d. (%d,%d)",(int)self,(int)(*s),(int)(*s+1));
	printf ("\n Signal %d is RED",(int)self);

	while (1)
	{
		temp=(int)(*s);
		if ((int)self==temp)
		{
			printf ("\n Signal %d is GREEN",(int)self);
			fflush(stdout);
			sleep(2);
			printf ("\n Signal %d is RED",(int)self);
			fflush(stdout);
			(*s)=self+1; // turn the next signal ON
	   		if (*(s)>*(s+1)) // if out of bounds then make it 0
				*s=0;
		}
		while ((int)self!=(int)*(s))
			sleep(0);		
	}
}
