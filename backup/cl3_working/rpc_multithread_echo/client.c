#include "echo.h"
#include <stdlib.h>
#include <string.h>

void getecho_1(char * host, char* str)
{
CLIENT *clnt;
data *input_struct, *output_struct;
int i,f ;
data *retval;
input_struct = (data*) malloc(sizeof(data));
strcpy(input_struct->buffer, str);
clnt = clnt_create(host, PORTPROG, PORTVERSION, "udp");

if (clnt == NULL)
{
clnt_pcreateerror(host);
exit(1);
}
retval=(data*)malloc(sizeof(data));	
getechoserver_1(input_struct, retval, clnt);
clnt_destroy(clnt);
printf("\n Server response: %s ", retval->buffer);
}

main(int argc, char* argv[])
{
char *host;
char str[256];
host = argv[1];
while(1)
{
	printf("\nEnter string to send to server:");
	scanf("%s", str);	
	getecho_1(host, str);
}
}
