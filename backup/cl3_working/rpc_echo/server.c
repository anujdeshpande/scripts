#include<rpc/rpc.h>
#include "echo.h"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<netdb.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>


data* getechoserver_1(data*p1, CLIENT *client)
{
	data *b1;	
	b1=(data*)malloc(sizeof(data));
	strcpy(b1->buffer, p1->buffer);
	printf("\nEcho response: %s",b1->buffer);
	fflush(stdout);
        fflush(stdout);
	return b1;
}
data* getechoserver_1_svc(data *p1, struct svc_req *svc)
{
	CLIENT  *client;
	return(getechoserver_1(p1,client));	
}


