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
	
	EnQueue(Queue,10);
	EnQueue(Queue,20);
	EnQueue(Queue,30);
	EnQueue(Queue,40);
	EnQueue(Queue,50);
	
	Display(Queue);								//|F10|20|30|40|R50|
	
	iDelData=DeQueue(Queue);
	if(iDelData!=-1)
		printf("%d IS DELETED.\n\n",iDelData);	//10
	else
		printf("QUEUE IS EMPTY\n\n");
	
	Display(Queue);								//|__|F20|30|40|R50|
	
	iDelData=DeQueue(Queue);					//20
	printf("%d IS DELETED.\n\n",iDelData);				
	
	iDelData=DeQueue(Queue);					//30
	printf("%d IS DELETED.\n\n",iDelData);	

	Display(Queue);								//|__|__|__|F40|R50|
	
	EnQueue(Queue,60);										
	EnQueue(Queue,70);
	EnQueue(Queue,80);

	Display(Queue);								//|60|70|R80|F40|50|
	
	EnQueue(Queue,90);							//QUEUE IS FULL..
	
	iDelData=DeQueue(Queue); 					//40
	printf("%d IS DELETED.\n\n",iDelData);				

	iDelData=DeQueue(Queue);					//50
	printf("%d IS DELETED.\n\n",iDelData);	

	Display(Queue);								//|F60|70|R80|__|__|	

	iDelData=DeQueue(Queue);			     	//60
	printf("%d IS DELETED.\n\n",iDelData);				
	
	Display(Queue);								//|__|F70|R80|__|__|

	return 0;
}
void EnQueue(int *pQueue,int iData)
{
	if(IsQueueFull())
	{
		printf("QUEUE IS FULL\n\n");
		return;
	}
	if(g_iRear==MAX-1)							//SURELY g_iFront NOT ON ZERO
		g_iRear=-1;
	pQueue[++g_iRear]=iData;
}
int DeQueue(int *pQueue)
{
	int iDelData;
	if(IsQueueEmpty())
		return -1;
	iDelData=pQueue[g_iFront];
	
	if(g_iFront==g_iRear)						//SURELY 1 ELEMENT
	{
		g_iRear=-1;
		g_iFront=0;
	}
	else if(g_iFront==MAX-1)								 
		g_iFront=0;
	else
		g_iFront++;
	
	return iDelData;
}
int IsQueueFull(void)
{
	if(((g_iFront==0)&&(g_iRear==MAX-1)||((g_iRear!=-1)&&(g_iFront==g_iRear+1))))
		return 1;								// ABOVE CONDITION 1-NORMAL QUEUE 2-CIRCULAR QUEUE
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
	int iCounter=g_iFront;
	if(-1==g_iRear)
	{
		printf("QUEUE IS EMPTY\n\n");
		return;
	}
	if(g_iRear<g_iFront)
	{
		for(;iCounter<=MAX-1;iCounter++)		//iCounter ALREADY AT g_iFront 	
			printf("|%d|",pQueue[iCounter]);
		iCounter=0;								//NOW GOES FOR CIRCULAR DISPLAY iCounter CHANGED TO "0"
	}
	for(;iCounter<=g_iRear;iCounter++)			//iCounter ALREADY SET ACCORDING IT'S REQUIREMENT
		printf("|%d|",pQueue[iCounter]);
	printf("\n\n");
}

