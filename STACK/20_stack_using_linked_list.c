#include<stdio.h>
#include<malloc.h>
#define MAX 5
struct Node
{
	int iNo;
	struct Node *pNext;
};
int Pop(struct Node **ppHead);
int IsFull(struct Node *pHead);
int IsEmpty(struct Node *pHead);
void Display(struct Node *pHead);
int CountNodes(struct Node *pHead);
void DeleteAll(struct Node **ppHead);
void Push(struct Node **ppHead,int iData);
int main(void)
{
	int iPoppedData;
	struct Node *pStack=NULL;
	
	Display(pStack);
	printf("\n");
	
	Push(&pStack,50);
	Push(&pStack,40);
	Push(&pStack,30);
	Push(&pStack,20);
	Push(&pStack,10);

	printf("------AFTER PUSH------\n\n");
	Display(pStack);
	printf("\n");
	
	iPoppedData=Pop(&pStack);
	if(iPoppedData != -1)
		printf("\n%d IS DELETED\n\n",iPoppedData);
	else
		printf("\nSTACK IS EMPTY\n\n");
	
	printf("------AFTER POP------\n\n");
	Display(pStack);
	printf("\n");
	
	if(pStack!=NULL)
	{
		DeleteAll(&pStack);
		pStack=NULL;
	}

	printf("------AFTER DELETE ALL------\n");
	Display(pStack);
	
	return 0;
}
void Push(struct Node **ppHead,int iData)
{
	struct Node *pNewNode=NULL;
	if(IsFull(*ppHead))
	{
		printf("\nSTACK IS OVERFLOW\n\n");
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
int Pop(struct Node **ppHead)
{
	int iDelData;
	struct Node *pTemp=NULL;
	if(IsEmpty(*ppHead))
	{
		printf("\nSTACK IS EMPTY\n\n");
		return -1; 
	}
	pTemp=*ppHead;
	*ppHead=pTemp->pNext;
	iDelData=pTemp->iNo;
	pTemp->pNext=NULL;
	free(pTemp);
	pTemp=NULL;
	return iDelData;
}
int IsFull(struct Node *pHead)
{
	int iCount;
	iCount=CountNodes(pHead);
	if(iCount==MAX)
		return 1;
	return 0;
}
int IsEmpty(struct Node *pHead)
{
	if(NULL==pHead)
		return 1;
	return 0;
}
void Display(struct Node *pHead)
{
	if(NULL==pHead)
	{
		printf("\nSTCAK IS EMPTY\n");
		return;
	}
	while(pHead!=NULL)
	{
		printf("\t%d\n",pHead->iNo);
		pHead=pHead->pNext;
	}
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
