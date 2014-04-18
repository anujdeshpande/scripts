#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<pthread.h>
#include<sys/socket.h>
#include<string.h>
#include<stdlib.>

void *communicate();
int cno;

int main()
{
int sockfd, client_sockfd, i, client_len, temp;
struct sockadd_in my_addr,client_addr;
char msg[25];
pthread_t thread;

if((sockfd=socket(AF_INET, SOCK_STREAM,0))==-1)
    printf("Error in creating socket\n");
    
    printf("socket created\n");
    
    my_addr.sin_family = AF_INET;
    my_add.sin_port = htons(5000);
    my_add.sin_addr.s_addr=INADDR_ANY;
    
if((temp=bind(sockfd, (struct sockaddr *)&my_addr,sizeof(struct sockaddr_in)))==-1)
    printf("Error in binding\n");
    
    printf("socket bound\n");
    
    if((temp=listen(sockfd,10))==-1)
