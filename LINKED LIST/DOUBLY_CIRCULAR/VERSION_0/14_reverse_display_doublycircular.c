#include<stdio.h>
#include<malloc.h>
struct Node
{
	struct Node *pPrev;
	int iNo;
	struct Node *pNext;
};
void Display(struct Node *pHead,struct Node *pTail);
void DeleteAll(struct Node **ppHead,struct Node **ppTail);
void ReverseDisplay(struct Node *ppHead,struct Node *ppTail);
void InsertFirst(struct Node **ppHead,struct Node **ppTail,int iData);
int main(void)
{
	struct Node *pFirst=NULL;
	struct Node *pLast=NULL;
	
	Display(pFirst,pLast);
	
	InsertFirst(&pFirst,&pLast,50);
	InsertFirst(&pFirst,&pLast,40);
	InsertFirst(&pFirst,&pLast,30);
	InsertFirst(&pFirst,&pLast,20);
	InsertFirst(&pFirst,&pLast,10);

	Display(pFirst,pLast);
	
	ReverseDisplay(pFirst,pLast);
	
	Display(pFirst,pLast);
	
	if(pFirst!=NULL)
	{
		DeleteAll(&pFirst,&pLast);
		pFirst=NULL;
		pLast=NULL;
	}
	
	Display(pFirst,pLast);
	
	return 0;
}
void Display(struct Node *pHead,struct Node *pTail)
{
	if(NULL==pHead)
	{
		printf("LINKED LIST IS EMPTY\n\n");
		return;
	}
	do
	{
		printf("|%d|->",pHead->iNo);
		pHead=pHead->pNext;
	}while(pHead!=pTail->pNext);
	printf("\n\n");
}
void DeleteAll(struct Node **ppHead,struct Node **ppTail)
{
	struct Node *pTemp=NULL;
	(*ppTail)->pNext=NULL;
	while(*ppHead!=NULL)
	{
		pTemp=*ppHead;
		*ppHead=pTemp->pNext;
		pTemp->pNext=NULL;
		free(pTemp);
	}
	pTemp=NULL;
	*ppHead=NULL;
}
void InsertFirst(struct Node **ppHead,struct Node **ppTail,int iData)
{
	struct Node *pNewNode=NULL;
	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("MEMORY ALLOCATION FAILED\n\n");
		return;
	}
	pNewNode->iNo=iData;
	if(NULL==*ppHead)
		*ppHead=*ppTail=pNewNode;
	else
	{
		pNewNode->pNext=*ppHead;
		(*ppHead)->pPrev=pNewNode;
		*ppHead=pNewNode;
	}
	(*ppHead)->pPrev=*ppTail;
	(*ppTail)->pNext=*ppHead;						//CIRCULAR EFFECT				
}
void ReverseDisplay(struct Node *pHead,struct Node *pTail)
{
	if(NULL==pHead)
		return;
	do
	{
		printf("|%d|->",pTail->iNo);
		pTail=pTail->pPrev;
	}while(pTail!=pHead->pPrev);
	printf("\n\n");
}
