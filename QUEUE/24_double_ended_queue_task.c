#include<stdio.h>
#define MAX 6

int IsQueueFull(void);
int IsQueueEmpty(void);
void Display(int *pQueue);
int DeQueueFromRear(int *pQueue);
int DeQueueAtFront(int *pQueue);
void EnQueueAtRear(int *pQueue,int iData);
void EnQueueFromFront(int *pQueue,int iData);

int g_iRear=-1;
int g_iFront=0;

int main(void)
{
	int Queue[MAX]={0};
	int iDelData;
	
	Display(Queue);
	
	EnQueueAtRear(Queue,10);
	EnQueueAtRear(Queue,20);
	EnQueueAtRear(Queue,30);

	Display(Queue);									//|F10|20|R30|__|__|__|

	EnQueueFromFront(Queue,40);
	EnQueueFromFront(Queue,50);
	EnQueueFromFront(Queue,60);
	
	Display(Queue);									//|10|20|R30|60F|50|40|

	EnQueueAtRear(Queue,70);
	EnQueueFromFront(Queue,80);						//QUEUE IS FULL
	
	iDelData=DeQueueFromRear(Queue);
	if(iDelData!=-1)
		printf("%d IS DELETED.\n\n",iDelData);		//30
	else
		("QUEUE IS EMPTY.\n\n");
	
	iDelData=DeQueueFromRear(Queue);				//20
	printf("%d IS DELETED.\n\n",iDelData);

	iDelData=DeQueueFromRear(Queue);
	printf("%d IS DELETED.\n\n",iDelData);			//10

	iDelData=DeQueueFromRear(Queue);				
	printf("%d IS DELETED.\n\n",iDelData);			//40

	Display(Queue);									//|__|__|__|60F|50R|__|
	
	return 0;
}
int IsQueueFull(void)
{
	if((g_iFront==0 && g_iRear==MAX-1) ||(g_iRear!=-1 && g_iRear==g_iFront-1))
		return 1;
	return 0;
}
int IsQueueEmpty(void)
{
	if(-1==g_iRear && 0 == g_iFront)	//---------------------------
		return 1;
	return 0;
}
void Display(int *pQueue)
{
	int iCounter=g_iFront;
	if(IsQueueEmpty())		//-----------------------------
	{
		printf("QUEUE IS EMPTY\n\n");
		return;
	}
	if(g_iRear<g_iFront)
	{
		for(;iCounter<=MAX-1;iCounter++)
			printf("|%d|",pQueue[iCounter]);
		iCounter=0;
	}
	for(;iCounter<=g_iRear;iCounter++)
			printf("|%d|",pQueue[iCounter]);
	printf("\n\n");	
}
int DeQueueFromRear(int *pQueue)
{
	int iDelData;
	if(IsQueueEmpty())
		return -1;
	
	iDelData=pQueue[g_iRear];

	if(g_iRear==g_iFront)	//--------------------
	{
		g_iRear=-1;
		g_iFront=0;
	}
	else if(0==g_iRear)
		g_iRear=MAX-1;
	else
		g_iRear--;
	
	return iDelData;
}
int DeQueueAtFront(int *pQueue)
{
	int iDelData;
	if(IsQueueEmpty())
		return -1;
	
	iDelData=pQueue[g_iFront];
	if(g_iFront==MAX-1)
		g_iFront=0;
	else if(g_iFront==g_iRear)
	{
		g_iRear=-1;
		g_iFront=0;
	}
	else
		g_iFront++;
	
	return iDelData;
}
void EnQueueAtRear(int *pQueue,int iData)
{
	if(IsQueueFull())
		return;
	
	if(g_iRear==MAX-1)
		g_iRear=-1;
	
	pQueue[++g_iRear]=iData;
}
void EnQueueFromFront(int *pQueue,int iData)
{
	if(IsQueueFull())
		return;
	
	if(0==g_iFront)
		g_iFront=MAX;
	
	pQueue[--g_iFront]=iData;
	return;
}
