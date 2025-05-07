#include<stdio.h>
#include<malloc.h>
#define MAX 5
struct Node 
{
	int iNo;
	struct Node *pNext;
};
void Display(struct Node *pHead);
int DeQueue(struct Node **ppHead);
int CountNodes(struct Node *pHead);
int IsQueueFull(struct Node *pHead);
int isQueueEmpty(struct Node *pHead);
void DeleteAll(struct Node **ppHead);
void EnQueue(struct Node **ppHead,int iData);
int main(void)
{
	int iDelData;
	struct Node *pQueue=NULL;
	
	Display(pQueue);
	printf("\n");
	
	EnQueue(&pQueue,50);
	EnQueue(&pQueue,40);
	EnQueue(&pQueue,30);
	EnQueue(&pQueue,20);
	EnQueue(&pQueue,10);

	printf("------AFTER ENQUEUE------\n\n");
	Display(pQueue);
	printf("\n");
	
	iDelData=DeQueue(&pQueue);
	if(iDelData != -1)
		printf("\n%d IS DELETED\n\n",iDelData);
	else
		printf("\nSTACK IS EMPTY\n\n");
	
	printf("------AFTER DEQUEUE------\n\n");
	Display(pQueue);
	printf("\n");
	
	if(pQueue!=NULL)
	{
		DeleteAll(&pQueue);
		pQueue=NULL;
	}

	printf("\n------AFTER DELETE ALL------\n");
	Display(pQueue);
	
	return 0;
}
void EnQueue(struct Node **ppHead,int iData)
{
	struct Node *pNewNode=NULL;
	if(IsQueueFull(*ppHead))
	{
		printf("\nQUEUE IS FULL\n\n");
		return;
	}
	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("\nMEMORY ALLOCATION FAILED\n\n");
		return;
	}
	pNewNode->iNo=iData;
	pNewNode->pNext=*ppHead;
	*ppHead=pNewNode;
}
int DeQueue(struct Node **ppHead)
{
	int iDelData;
	struct Node *pTemp=NULL;
	if(IsQueueEmpty(*ppHead))
	{
		printf("\nQUEUE IS EMPTY\n\n");
		return;
	}
	pTemp=*ppHead;
	if(pTemp->pNext!=NULL)
	{
		while(pTemp->pNext->pNext!=NULL)
			pTemp=pTemp->pNext;
		iDelData=pTemp->pNext->iNo;
		free(pTemp->pNext);
		pTemp->pNext=NULL;
	}
	else
	{
		iDelData=pTemp->iNo;
		free(pTemp);
		*ppHead=pTemp=NULL;
	}
	return iDelData;
}
int IsQueueFull(struct Node *pHead)
{
	int iCount=0;
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
void Display(struct Node *pHead)
{
	if(NULL==pHead)
	{
		printf("\nQUEUE IS EMPTY\n");
		return;
	}
	while(pHead!=NULL)
	{
		printf("|%d|",pHead->iNo);
		pHead=pHead->pNext;
	}
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
