#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int sockfd,port;
    struct hostent *h;
    h=gethostbyname(argv[1]);
    for(port=0;port<65535;port++)
    {
        //printf("in loop");
        struct sockaddr_in t;
        if((sockfd=socket(AF_INET,SOCK_STREAM,0)==-1))
        {
            perror("error in creating socket\n");
            return(1);
        }
        t.sin_family=AF_INET;
        t.sin_port=htons(port);
        t.sin_addr= *((struct in_addr *)h->h_addr);
        memset(&(t.sin_zero),'\0',8);
        
        if(connect(sockfd, (struct sockaddr *)&t,sizeof(struct sockaddr)) == -1)
        {
            
            close(sockfd);
        }
        else
        {
            printf("%i port open!\n",port);
            close(sockfd);
        }
    }
}
