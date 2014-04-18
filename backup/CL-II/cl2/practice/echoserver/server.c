#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<pthread.h>
#include<sys/socket.h>
#include<string.h>
#include<stdlib.h>

void *communicate();
int cno;

int main()
{
int sockfd, client_sockfd, i, client_len, temp;
struct sockaddr_in my_addr,client_addr;
char msg[25];
pthread_t thread;

if((sockfd=socket(AF_INET, SOCK_STREAM,0))==-1){
    printf("Error in creating socket\n");return 0;}
    
    printf("socket created\n");
    
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(5000);
    my_addr.sin_addr.s_addr=INADDR_ANY;
    
if((temp=bind(sockfd, (struct sockaddr *)&my_addr,sizeof(struct sockaddr_in)))==-1){
    printf("Error in binding\n");return 0;}
    
    printf("socket bound\n");
    
    if((temp=listen(sockfd,10))!=0)
    printf("error in listening\n");
    
    printf("listening..\n");
    
    while(1)
    {
    
        printf("waiting for connection..\n");
        
        client_sockfd = accept(sockfd,(struct sockaddr *)&client_addr,&client_len);
        
        printf("Client connected\n"); 
        
        cno=client_sockfd;
        temp = pthread_create(&thread, NULL, communicate, NULL);
        
        if(temp!=0){
          printf("error in creating thread\n");
        break;
        }
      }
      close(sockfd);
      printf("Exiting..\n");
      return 0;
}

void *communicate()
{
    int temp,i;
    char msg[25];
    int client_sockfd=cno;
    printf("Thread created\n");
    
    while(1)
    {
        for(i=0;i<25;i++) msg[i]='\0';
        
        if((temp = read(client_sockfd,(void *)msg,25)<=0))
            printf("error in read\n");
            
            printf("Message: %s",msg);
            if(strcmp("exit", msg)==0) {printf("\nClient exited..."); break;}
            
            temp=write(client_sockfd, (void *)msg, strlen(msg));	
			if(temp<=0)	{printf("\nError in sending msg.\n"); return;}
			printf("\nSent: %s", msg);	
			

		}
	}
        
