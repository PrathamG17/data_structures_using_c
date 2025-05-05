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
int g_iFlag=0;

int main(void)
{
	int iChoice;
	int Queue[MAX]={0};
	
	while(1)
	{
		printf("\n\t---------Menu--------\n");
		printf("\n\t1)EnQueue At Rear.");
		printf("\n\t2)DeQueue From Rear.");
		printf("\n\t3)EnQueue From Front.");
		printf("\n\t4)DeQueue At Front.");
		printf("\n\t5)Exit.");
		printf("\n\t---------------------\n");
		
		printf("\n\t-->Enter Your Choice : ");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1: if(IsQueueFull())
					{
						Display(Queue);
						break;
					}
					
					printf("\n\t-->Enter Data : ");
					scanf("%d",&iChoice);
					EnQueueAtRear(Queue,iChoice);
					Display(Queue);
					break;
			
			case 2: iChoice=DeQueueFromRear(Queue);
					if(iChoice!=-1)
						printf("\n\t%d IS DELETED.\n",iChoice);
					else
						("\n\tQUEUE IS EMPTY.");
					Display(Queue);
					break;
					
			case 3: if(IsQueueFull())
					{
						Display(Queue);
						break;
					}
					
					printf("\n\t-->Enter Data : ");
					scanf("%d",&iChoice);
					EnQueueFromFront(Queue,iChoice);
					Display(Queue);
					break;	

			case 4: iChoice=DeQueueAtFront(Queue);
					if(iChoice!=-1)
						printf("\n\t%d IS DELETED.\n",iChoice);
					else
						("\n\tQUEUE IS EMPTY.");
					Display(Queue);
					break;
					
			case 5: exit(1);
			
			default: printf("\n\tEnter Valid Choice.");
		}
	}
}
int IsQueueFull(void)
{
	if((g_iFront==0 && g_iRear==MAX-1) ||(g_iRear!=-1 && g_iRear==g_iFront-1)||(1 == g_iFlag && -1 == g_iRear))
	{
		printf("\n\tQUEUE IS FULL.\n");
		return 1;
	}
	return 0;
}
int IsQueueEmpty(void)
{
	if((-1==g_iRear && 0 == g_iFront) && (0 == g_iFlag) )
		return 1;
	return 0;
}
void Display(int *pQueue)
{
	int iCounter=g_iFront;
	if(IsQueueEmpty())
	{
		printf("\n\tQUEUE IS EMPTY\n");
		return;
	}
	printf("\n\t");
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
	
	if(1 == g_iFlag)
		g_iRear=MAX-1;
	
	iDelData=pQueue[g_iRear];

	if(g_iRear==g_iFront)
	{
		g_iRear=-1;
		g_iFront=0;
	} 
	else if(0==g_iRear)
		g_iRear=MAX-1;
	else
		g_iRear--;
	
	if(g_iRear != -1 || g_iFront != 0)
		g_iFlag=0;
	
	return iDelData;
}
int DeQueueAtFront(int *pQueue)
{
	int iDelData;
	if(IsQueueEmpty())
		return -1;
	
	iDelData=pQueue[g_iFront];

	if(g_iFront==g_iRear)
	{
		g_iRear=-1;
		g_iFront=0;
	}
	else if(g_iFront==MAX-1)
		g_iFront=0;
	else
		g_iFront++;
	
	if(g_iRear != -1 || g_iFront != 0)
		g_iFlag=0;
	
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
	
	if(0 == g_iFront)
		g_iFlag=1;
	
	return;
}
