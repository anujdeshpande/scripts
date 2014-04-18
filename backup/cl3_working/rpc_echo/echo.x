const PORTLIMIT = 50 ;
struct input{
	char buffer[256];
};

typedef struct input data;

program ECHOPROG{
version ECHOVERSION{
	data getechoserver(data) = 1;
} = 1;
} = 0x20000044;


