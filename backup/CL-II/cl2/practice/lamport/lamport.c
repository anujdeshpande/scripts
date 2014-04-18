#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

pthread_t id[3];
int clock_t1, clock_t2, clock_t3;
int sender=1;
pthread_mutex_t mutex_var;

void *increment1(void *interval)
{
    int *intr=(int*)interval;
    while(1)
    {
        sleep(2);
        clock_t1 += *intr;
        printf("\nClock1=%d\n",clock_t1);
    }
    
}
void *increment2(void *interval)
{
    int *intr=(int*)interval;
    while(1)
    {
        sleep(2);
        clock_t2 += *intr;
        printf("\nClock2=%d\n",clock_t2);
    }
    
}
void *increment3(void *interval)
{
    int *intr=(int*)interval;
    while(1)
    {
        sleep(2);
        clock_t3 += *intr;
        printf("\nClock3=%d\n",clock_t3);
    }
    
}

void* clock1(void *interval)
{
    int *intr = (int*)interval;
    pthread_t id1;
    
    pthread_create(&id1,NULL,&increment1,interval);
    
    while(1)
    {
        sleep(5);
        pthread_mutex_lock(&mutex_var);
        
        printf("\nThread 1 received message at %d from %d ", clock_t1,sender);
        
        if(sender==2 && clock_t1 < clock_t2)
        {
             clock_t1 = clock_t2+1;
             printf("\nThread 1 updates it clock to%d ",clock_t1);
        }
        if(sender==3 && clock_t1 < clock_t3)
        {
             clock_t1 = clock_t3+1;
             printf("\nThread 1 updates it clock to%d ",clock_t1);
        }
        
        sender=1;
        pthread_mutex_unlock(&mutex_var);
        
        printf("\nThread1 sends message at%d ",clock_t1);
        
    }
    pthread_join(id1,NULL);
    
}
void* clock2(void *interval)
{
    int *intr = (int*)interval;
    pthread_t id2;
    
    pthread_create(&id2,NULL,&increment2,interval);
    
    while(1)
    {
        sleep(5);
        pthread_mutex_lock(&mutex_var);
        
        printf("\nThread 2 received message at %d from %d ", clock_t2,sender);
        
        if(sender==1 && clock_t2 < clock_t1)
        {
             clock_t2 = clock_t1+1;
             printf("\nThread 2 updates it clock to%d ",clock_t2);
        }
        if(sender==3 && clock_t2 < clock_t3)
        {
             clock_t2 = clock_t3+1;
             printf("\nThread 2 updates it clock to%d ",clock_t2);
        }
        
        sender=2;
        pthread_mutex_unlock(&mutex_var);
        
        printf("\nThread2 sends message at%d ",clock_t2);
        
    }
    pthread_join(id2,NULL);
    
}
void* clock3(void *interval)
{
    int *intr = (int*)interval;
    pthread_t id3;
    
    pthread_create(&id3,NULL,&increment3,interval);
    
    while(1)
    {
        sleep(5);
        pthread_mutex_lock(&mutex_var);
        
        printf("\nThread 3 received message at %d from %d ", clock_t3,sender);
        
        if(sender==1 && clock_t3 < clock_t1)
        {
             clock_t3 = clock_t1+1;
             printf("\nThread 3 updates it clock to%d ",clock_t3);
        }
        if(sender==2 && clock_t3 < clock_t2)
        {
             clock_t3 = clock_t2+1;
             printf("\nThread 3 updates it clock to%d ",clock_t3);
        }
        
        sender=3;
        pthread_mutex_unlock(&mutex_var);
        
        printf("\nThread3 sends message at%d ",clock_t3);
        
    }
    pthread_join(id3, NULL);
    
}
int main()
{
	int interval[3];
	
	interval[0]=6;
	interval[1]=8;
	interval[2]=10;
	
	//create threads
	pthread_create(&id[0],NULL,&clock1,(void*)&interval[0]);
	pthread_create(&id[1],NULL,&clock2,(void*)&interval[1]);
	pthread_create(&id[2],NULL,&clock3,(void*)&interval[2]);
	
	//Join threads one by one
	pthread_join(id[0],NULL);
	pthread_join(id[1],NULL);
	pthread_join(id[2],NULL);
}
