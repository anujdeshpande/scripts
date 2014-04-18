#include "soapH.h"
#include "calc.nsmap"
#include <math.h>
int main(int argc, char **argv)
{
    int x,y;
    struct soap *soap = soap_new();
    x = soap_bind(soap, NULL, 8000, 100);
    //printf("soap started");
    while(1)
    {
        y = soap_accept(soap);
        soap_serve(soap);
        soap_end(soap);
    }
       soap_done(soap);
       soap_free(soap);
       return 0;
}
int ns__add(struct soap *soap,double a, double b, double *c)
{
    *c = a + b;
    return SOAP_OK;
}

int ns__sub(struct soap *soap,double a, double b, double *c)
{
    *c = a - b;
    return SOAP_OK;
}
