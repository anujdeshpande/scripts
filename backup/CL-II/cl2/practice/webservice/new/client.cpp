#include "soapcalcProxy.h"
#include "calc.nsmap"
#include <string.h>
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
        if(!strcasecmp(op,"add"))
        {
            cin>>a>>b;
            if(c.ns__add(a,b,&r)==SOAP_OK)
            cout<<a<<"+"<<b<<"="<<r;
        }
        else if(!strcasecmp(op,"exit"))
                break;
     }
return 0;
}

