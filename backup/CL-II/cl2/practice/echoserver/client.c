#include<stdio.h>
#include<sys/types.h>			
#include<sys/socket.h>
#include<pthread.h>
#include<netinet/in.h>
#include<string.h>
#include<netdb.h>
int main()
{
	int sockfd,i,temp;
	char msg[25], rmsg[25];
	struct sockaddr_in serv_addr;
	struct hostent *server;	//returned by gethostbyname()
	if((sockfd= socket(AF_INET, SOCK_STREAM, 0))==-1)
	{printf("\nError in creating socket...\n"); return 0;}
	
	printf("\nSocket created!");
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(5000);//converts a port number in host byte order to a port number in network byte order.
		
	server=(struct hostent *)gethostbyname("127.0.0.1");

    	bcopy(server->h_addr_list[0], &serv_addr.sin_addr.s_addr, server->h_length);
  
    
    if((temp = connect(sockfd, (struct sockaddr *)&serv_addr,sizeof(serv_addr)))!=0){
        printf("error in connecting\n"); return 0;}
        
        printf("connection created\n");
        
    while(1)
    {
        printf("enter data to be sent\n");
        scanf("%s",msg);
        
        if((temp = write(sockfd, (void *)msg, strlen(msg)))<=0)
            printf("error in sending msg\n");
        
        printf("message sent\n");
        
        for(i=0; i<25; i++) rmsg[i]=msg[i]='\0';
        
        if(temp= read(sockfd,(void *)rmsg, strlen(rmsg))<=0)
                printf("error in receiving msg\n");    
                
        printf("message received %s",rmsg);
    
        for(i=0; i<25; i++) rmsg[i]=msg[i]='\0';
    }
    close(sockfd);
    printf("exiting..\n");
    return 0;
 }
    
    
