const PORTLIMIT = 50 ;
struct input{
	char buffer[256];
};

typedef struct input data;

program PORTPROG{
version PORTVERSION{
	data getopenports(data) = 1;
} = 1;
} = 22855;


