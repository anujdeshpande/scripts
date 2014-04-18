//To SIMULATE ring algorithm

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int process[MAX],num,list[MAX],attach;

void ring(int place)
{
	int i;
	if(process[place]!=-1)
	{
		if(list[0]==process[place])	//a complete circle
			return;
		list[attach++]=process[place];	//not in the list
		printf("\nThe List sent from %d to next node\n",list[attach-1]);
		for(i=0;i<attach;i++)
			printf("%d\t",list[i]);
	
	}
	ring((place+1)%num);
}

int main()
{
	int i=0,max=-1,place=-1,crash=-1,elect=-1,j=0,next=-1;
	printf("Enter the number of processes:\t");
	scanf("%d",&num);
	printf("Enter the priorities of the project:\t");
	for(i=0;i<num;i++)
	{
		scanf("%d",&process[i]);
		if(process[i]>max)
		{
			max = process[i];
			place = i;
		}
	}
	printf("The current Co-ordinatr process is: %d\n",process[place]);
	printf("Enter the process that crashed:\t");
	scanf("%d",&crash);
	
	for(i=0;i<num;i++)	//finding and marking the process that crashed as -1 
		if(crash == process[i])
			process[i] = -1;
	
	printf("\nEnter the process that starts election:\t");
	scanf("%d",&elect);
	
	for(i=0;i<num;i++)	//The process that starts the election algorithm feels that it's having max priority and hence we place the co-ordinator in place
		if(elect==process[i])
			place = i;

		
	ring(place);
	max=0;			//The process that started the election algorithm present in list[0] finds the maximum priority process
	for(i=0;i<attach;i++)
		if(list[i]>list[max])
				max=i;
	for(i=0;i<attach-1;i++)	//Message is sent in a ring to declare winner
		printf("\nMessage from %d to %d saying Winner is %d \n",list[i],list[i+1],list[max]);
	
	printf("\nThe current Co-ordinator is: %d\n",list[max]);
	return 0;
}
