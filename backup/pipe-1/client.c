#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<fcntl.h>
#include <unistd.h>
#include<string.h>

# define SIZE 20

main()
{
  int writer;
  char msg[SIZE];

  while(1)
 {
  writer=open("pcp",O_WRONLY);
  printf("Produced:");
  scanf("%s",msg);
  write(writer,msg,SIZE); 
 close(writer);
 }
    



}
