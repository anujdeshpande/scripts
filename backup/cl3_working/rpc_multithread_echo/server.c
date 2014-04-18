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

bool_t getechoserver_1_svc(data *p1, data *b1, struct svc_req *svc)
{
	strcpy(b1->buffer, p1->buffer);
	printf("\nEcho response: %s",b1->buffer);
	fflush(stdout);
	return 1;
}
int portprog_1_freeresult(transp, xdr_result, result)
	SVCXPRT *transp;
	xdrproc_t xdr_result;
	caddr_t result;
{
	/*
	 * Insert additional freeing code here,
 * if needed
	 */
	(void) xdr_free(xdr_result, result);
}



