#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<signal.h>
#include<fcntl.h>

int listenfd;

void startServer(char *port)
{
    struct addrinfo hints, *res, *p;
    
    memset (&hints, 0, sizeof(hints));
    
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    getaddrinfo( NULL, port, &hints, &res);
    
    for (p = res; p!=NULL; p=p->ai_next)
    {
        listenfd = socket (p->ai_family, p->ai_socktype, 0);
        if (listenfd == -1) continue;
        if (bind(listenfd, p->ai_addr, p->ai_addrlen) == 0) break;
    }
    freeaddrinfo(res);
    listen (listenfd, 1000);
}

void respond(int client)
{
    char msg[10000];
    int  bytes_read;
    memset((void*)msg,(int)'\0',10000);
    
    bytes_read=recv(client,msg,10000,0);
    printf("%s\n",msg);
    
    send(client,"it works!!!",11,0);
    shutdown(client,SHUT_RDWR);
    close(client);
}
int main(int argc, char *argv[])
{
    struct sockaddr_in clientaddr;
    socklen_t addrlen;
    char PORT[6];
    strcpy(PORT,argv[1]);
    
    startServer(PORT);
    int client;
    
    while(client)
    {
        addrlen=sizeof(clientaddr);
        client=accept(listenfd,(struct sockaddr *)&clientaddr,&addrlen);
        respond(client);
    }
  return 0;
}
    
    
    
    
    
