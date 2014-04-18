#include "echo.h"
#include <stdlib.h>
#include <string.h>

void getecho_1(char * host, char* str)
{
CLIENT *clnt;
data *input_struct, *output_struct;
int i,f ;
input_struct = (data*) malloc(sizeof(data));
strcpy(input_struct->buffer, str);
clnt = clnt_create(host, ECHOPROG, ECHOVERSION, "udp");

if (clnt == NULL)
{
clnt_pcreateerror(host);
exit(1);
}
output_struct=getechoserver_1(input_struct, clnt);
clnt_destroy(clnt);
printf("\n Server response: %s ", output_struct->buffer);
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
