#include "soapH.h"
#include "calc.nsmap"

int main()
{
struct soap *soap = soap_new();
soap_bind(soap,NULL,8000,100);
while(1)
{
    soap_accept(soap);
    soap_serve(soap);
    soap_end(soap);
}
soap_done(soap);
soap_free(soap);
return 0;
}

int ns__add(struct soap *soap, double a, double b, double *c)
{
    *c=a+b;
    return SOAP_OK;
}
