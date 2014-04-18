#include "calc.nsmap"
#include "soapcalcProxy.h"
#include <iostream>
using namespace std;
int main()
{
calc c;
double a,b,r;
while(1)
{
    char op[4];
    cin>>op;
    if(!strcmp(op,"add"))
    {
        cin>>a>>b;
        if((c.ns__add(a,b,&r)==SOAP_OK))
           cout<<r;
    }
    else if(!strcmp(op,"exit"))
    {
        exit(1);
    }
}
return 0;
}
