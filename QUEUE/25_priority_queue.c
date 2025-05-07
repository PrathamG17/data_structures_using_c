#include<stdio.h>
#include<malloc.h>
#define MAX 5

struct Node 
{
	int iNo;
	int iPri;
	struct Node *pNext;
};

void Display(struct Node *pHead);
int DeQueue(struct Node **ppHead);
int CountNodes(struct Node *pHead);
int IsQueueFull(struct Node *pHead);
void DeleteAll(struct Node **ppHead);
int IsQueueEmpty(struct Node *pHead);
void EnQueue(struct Node **ppHead,int iData,int iPriority);

int main(void)
{
	int iDelData;
	struct Node *pQueue=NULL;
	
	Display(pQueue);						    //NULL
	
	EnQueue(&pQueue,70,4);
	EnQueue(&pQueue,30,2);
	EnQueue(&pQueue,10,1);
	EnQueue(&pQueue,100,5);
	EnQueue(&pQueue,50,3);
	
	Display(pQueue);						    //|100|70|50|30|10|
	
	iDelData=DeQueue(&pQueue);
	if(iDelData!=-1)
		printf("%d IS DELETED.\n\n",iDelData);	//100
	else
		printf("QUEUE IS EMPTY\n\n");
	
	Display(pQueue);							//|70|50|30|10|
	
	if(pQueue!=NULL)
	{
		DeleteAll(&pQueue);
		pQueue=NULL;
	}
	
	Display(pQueue);							//NULL
	
	return 0;
}
void Display(struct Node *pHead)
{
	if(NULL==pHead)
	{
		printf("QUEUE IS EMPTY\n\n");
		return;
	}
	while(pHead!=NULL)
	{
		printf("|%d|",pHead->iNo);
		pHead=pHead->pNext;
	}
	printf("\n\n");
}
int DeQueue(struct Node **ppHead)
{
	int iDelData;
	struct Node *pTemp=NULL;
	if(IsQueueEmpty(*ppHead))
		return -1;
	pTemp=*ppHead;
	*ppHead=pTemp->pNext;
	iDelData=pTemp->iNo;
	pTemp->pNext=NULL;
	free(pTemp);
	pTemp=NULL;
	return iDelData;
}
int CountNodes(struct Node *pHead)
{
	int iCount=0;
	while(pHead!=NULL)
	{
		iCount++;
		pHead=pHead->pNext;
	}
	return iCount;
}
void DeleteAll(struct Node **ppHead)
{
	struct Node *pTemp=NULL;
	while(*ppHead!=NULL)
	{
		pTemp=*ppHead;
		*ppHead=pTemp->pNext;
		pTemp->pNext=NULL;
		free(pTemp);
	}
	pTemp=NULL;
}
int IsQueueFull(struct Node *pHead)
{
	int iCount;
	iCount=CountNodes(pHead);
	if(iCount==MAX)
		return 1;
	return 0;
}
int IsQueueEmpty(struct Node *pHead)
{
	if(NULL==pHead)
		return 1;
	return 0;
}
void EnQueue(struct Node **ppHead,int iData,int iPriority)
{
	struct Node *pNewNode=NULL;
	struct Node *pTemp=NULL;
	
	if(IsQueueFull(*ppHead))
	{
		printf("QUEUE IS FULL\n\n");
		return;
	}
	
	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("MEMORY ALLOCATION FAILED\n\n");
		return;
	}
	pNewNode->iNo=iData;
	pNewNode->iPri=iPriority;
	
	pTemp=*ppHead;
	if(NULL==*ppHead||iPriority > (pTemp->iPri))
	{
		pNewNode->pNext=*ppHead;
		*ppHead=pNewNode;
	}
	else
	{
		while(pTemp->pNext!=NULL)
		{
			if(iPriority > (pTemp->pNext->iPri))
				break;
			pTemp=pTemp->pNext;
		}
		pNewNode->pNext=pTemp->pNext;
		pTemp->pNext=pNewNode;
	}
}
