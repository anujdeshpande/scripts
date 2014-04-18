struct input{
	char buffer[256];
};

typedef  struct input data;

program ECHO{
version ECHOVER{
	data getechoserver(data)=1;
}=1;
}=44;

