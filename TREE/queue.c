#include<malloc.h>
#include"tree.h"
#include"queue.h"
void EnQueue(struct Queue **ppHead,struct Node *pHead)
{
	struct Queue *pNewNode=NULL;
	struct Queue *pTemp=NULL;
	
	if(IsQueueFull(*ppHead))
		return;
	pNewNode=(struct Queue *)malloc(sizeof(struct Queue));
	if(NULL==pNewNode)
	{
		printf("MEMORY ALLOCATION FAILED\n\n");
		return;
	}
	pNewNode->pNode=pHead;
	pNewNode->pNext=NULL;
	if(*ppHead!=NULL)
	{
		pTemp=*ppHead;
		while(pTemp->pNext!=NULL)
			pTemp=pTemp->pNext;
		pTemp->pNext=pNewNode;
	}
	else
		*ppHead=pNewNode;
}
struct Node * DeQueue(struct Queue **ppHead)
{
	struct Queue *pTemp1=NULL;
	struct Node *pTemp2=NULL;
	if(IsQueueEmpty(*ppHead))
		return NULL;
	pTemp1=*ppHead;
	*ppHead=pTemp1->pNext;
	pTemp2=pTemp1->pNode;
	pTemp1->pNext=NULL;
	free(pTemp1);
	pTemp1=NULL;
	return pTemp2;
}
int IsQueueFull(struct Queue *pHead)
{
	if(MAX==CountNodesQueue(pHead))
		return 1;
	return 0;
}
int IsQueueEmpty(struct Queue *pHead)
{
	if(NULL==pHead)
		return 1;
	return 0;
}
int CountNodesQueue(struct Queue *pHead)
{
	int iCount=0;
	while(pHead!=NULL)
	{
		iCount++;
		pHead=pHead->pNext;
	}
	return iCount;
}
