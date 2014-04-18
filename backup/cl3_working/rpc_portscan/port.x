const PORTLIMIT = 50 ;
struct input{
	char host[40];
	int start;
	int end;
};
struct output{
	int total;
	int port_no[PORTLIMIT];
};

typedef struct input in;
typedef struct output out;


program PORTPROG{
version PORTVERSION{
	out getopenports(in) = 1;
} = 1;
} = 22855;


