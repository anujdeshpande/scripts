#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <unistd.h>
#include<string.h>


# define SIZE 20
# define CHMOD 0777

main()
{
  int reader;
  char msg[SIZE];
 
  if(mkfifo("pcp",CHMOD)==-1)
   {
	printf("Already exits...\n");
	//exit(0);
   }
	
  while(strcmp(msg,"0")!=0)
  {
    reader=open("pcp",O_RDONLY);
    read(reader,msg,SIZE);
    printf("Consumed :%s\n",msg);	
    bzero(msg,SIZE);
    close(reader);
   }	 	 

}
 		   
