//To SIMULATE bully algorithm

#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int process[MAX], num, flag[MAX];

int bully(int place)
{
	int i;
	for(i=0;i<num;i++)	//Sending election message to processes having greater priority
	{
		if(process[i]>process[place])
			printf("\nElection message sent from %d to %d\n",process[place],process[i]);
		else		//else set the flag as these processes cannot be the co-ordinator
			flag[i]=1;
	}
	
	for(i=0;i<num;i++)	//The process that has greater priority takes over the process that just sent the election message 
	{
		if(flag[i]!=1&&process[i]>process[place])
		{
			printf("\nTakeover message sent from %d to %d\n",process[i],process[place]);
			flag[place]=1;
		}
	}		//Call the bully algorithm for those process who received a election message from a low priority process
	for(i=0;i<num;i++)
	{
		if(flag[i]==0)
			place = bully(i);
	}
	return place;
}

int main()
{
	int i=0,max=-1,place=-1,crash=-1,elect=-1,j=0;
	printf("Enter the number of processes:\t");
	scanf("%d",&num);
	printf("Enter the priorities of the processes:\t");
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
	
	for(i=0;i<num;i++)		//finding and marking the process flag as 1
		if(crash == process[i])
			flag[i] = 1;
	
	printf("\nEnter the process that starts election:\t");
	scanf("%d",&elect);
	
	for(i=0;i<num;i++)	//The process that starts the election algorithm feels that it's having max priority and hence we place the co-ordinator in place
		if(elect==process[i])
			place = i;
		
	place = bully(place);
	printf("\nThe current Co-ordinator is: %d\n",process[place]);
	
	for(i=0;i<num;i++)	//Victory message is sent from the winner to each other process
	{
		if(i!=place && process[i]<process[place])
			printf("\nVictory message from %d to %d\n",process[place],process[i]);
	}
	return 0;
}
