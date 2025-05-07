#include<stdio.h>
#define MAX 5
int IsQueueFull(void);
int IsQueueEmpty(void);
int DeQueue(int *pQueue);
void Display(int *pQueue);
void EnQueue(int *pQueue,int iData);
int g_iRear=-1;
int g_iFront=0;
int main(void)
{
	int Queue[MAX]={0};
	int iDelData;
	
	Display(Queue);
	
	EnQueue(Queue,50);
	EnQueue(Queue,40);
	EnQueue(Queue,30);
	EnQueue(Queue,20);
	EnQueue(Queue,10);
	
	printf("------AFTER ENQUEUE------\n\n");
	Display(Queue);
	printf("\n");

	iDelData=DeQueue(Queue);
	if(iDelData != -1)
		printf("\n%d IS DELETED\n\n",iDelData);
	else
		printf("\nSTACK IS EMPTY\n\n");
	
	printf("------AFTER DEQUEUE------\n\n");
	Display(Queue);
	printf("\n");

	return 0;
}
void EnQueue(int *pQueue,int iData)
{
	if(IsQueueFull())
	{
		printf("\nQUEUE IS FULL\n\n");
		return;
	}
	pQueue[++g_iRear]=iData;
}
int DeQueue(int *pQueue)
{
	int iDelData;
	if(IsQueueEmpty())
	{
		printf("\nQUEUE IS EMPTY\n\n");
		return;
	}
	iDelData=pQueue[g_iFront];
	if(g_iFront==g_iRear)
	{
		g_iRear=-1;
		g_iFront=0;
	}
	else
		g_iFront++;
	return iDelData;
}
int IsQueueFull(void)
{
	if(g_iRear==MAX-1)
		return 1;
	return 0;
}
int IsQueueEmpty(void)
{
	if(-1==g_iRear)
		return 1;
	return 0;
}
void Display(int *pQueue)
{
	int iCounter;
	if(-1==g_iRear)
	{
		printf("\nQUEUE IS EMPTY\n\n");
		return;
	}
	for(iCounter=g_iFront;iCounter<=g_iRear;iCounter++)
		printf("|%d|",pQueue[iCounter]);
}
