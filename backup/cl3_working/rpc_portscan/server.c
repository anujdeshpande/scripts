#include<rpc/rpc.h>
#include "port.h"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<netdb.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>

out * getopenports_1(in *p1, CLIENT *client)
{
	out *output_struct;
	int socketfd, port;
	struct hostent * he;
	int j=1;
	output_struct=(out *) malloc(sizeof(out));
	if((he=gethostbyname(p1->host))==NULL)
	{	
	perror("Unable to resolve hostname");
	exit(1);
	}
	printf("Port number \t Status");
	for(port=p1->start; port<=p1->end; port++)
	{
		struct sockaddr_in their_address;
		if((socketfd=socket(AF_INET, SOCK_STREAM, 0))==-1)
		{
			perror("\n Unable to create socket");
			exit(1);
		}
		their_address.sin_family=AF_INET;
		their_address.sin_port=htons(port);
		their_address.sin_addr=*((struct in_addr*)he->h_addr);
		memset(&(their_address.sin_zero), '\0', 8);
		if(connect(socketfd,(struct sockaddr*)&their_address, sizeof(struct sockaddr))==-1)
		{
			close(socketfd);
		}
		else{
		output_struct->port_no[j]=port;
		printf("\nOpen");
		j++;
		close(socketfd);
		}
	}
	output_struct->total=j-1;
	return output_struct;
}

out * getopenports_1_svc(in *p1, struct svc_req *svc)
{
	CLIENT * client;
	return (getopenports_1(p1,client));
}

