#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>

#define SIZE 27

int main()
{
 key_t key;
 key=5678;
 char *shm,c,*s;
 int shmid;
 int money,x;
 

if((shmid=shmget(key,SIZE,IPC_CREAT | 0666))<0)
{
    perror("error in creating shared memory\n");
    printf("error in creating shared memory\n");
    exit(1);
}
if((shm=shmat(shmid,NULL,0))==(char*)-1)
{
    perror("error in attaching\n");
    printf("error in attaching\n");
    exit(1);
}
 s=shm;
 printf("attached the segment to the dataspace\n Enter Money\n");
scanf("%d",&money);


/*for(c='a';c<='z';c++)
{
    printf("%c",c);
    *s++=c;
}*/
*s=money;
s++;
scanf("%d",&x);
//s++;
printf("%d",(int)*s);

/* *s=NULL;
 while(*shm!='*')
     sleep(1);
     exit(0);*/
}

