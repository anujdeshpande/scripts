/*take care of spaces else nsmap file is not created*/
//gsoap ns service name: calc
//gsoap ns schema namespace: urn:calc
//gsoap ns service location: localhost:8000

int ns__add(double a, double b, double *c); /* return type double not allowed?? */
int ns__sub(double a, double b, double *c);
