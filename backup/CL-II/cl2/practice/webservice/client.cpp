#include "soapcalcProxy.h"
#include "calc.nsmap"
#include <string.h>
#include <iostream>

using namespace std;

int main()
{
    calc c;
    double a,b,r;
    cout<<"web service example add x y";
    while(1)
    {
        char op[4];
        cout<<">>>";
        cin>>op;
        if(!strcasecmp(op,"add"))
        {
            cin>>a>>b;
            if(c.ns__add(a,b,&r)== SOAP_OK)
                cout <<a <<"+"<<b<<" = " << r << endl;
        }
        else if(!strcasecmp(op,"sub"))
        {
            cin>>a>>b;
            if(c.ns__sub(a,b,&r)== SOAP_OK)
                cout <<a <<"-"<<b<<" = " << r << endl;
        
        }
        else if(!strcasecmp(op,"exit"))
        {
            break;
        }
        
    }
    return 0;
}



