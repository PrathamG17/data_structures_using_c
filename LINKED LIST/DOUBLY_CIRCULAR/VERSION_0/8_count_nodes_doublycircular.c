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
void InsertFirst(struct Node **ppHead,struct Node **ppTail,int iData);
int CountNodes(struct Node *pHead,struct Node *pTail);
int main(void)
{
	int iCount;
	struct Node *pFirst=NULL;
	struct Node *pLast=NULL;
	
	Display(pFirst,pLast);
	
	InsertFirst(&pFirst,&pLast,30);
	InsertFirst(&pFirst,&pLast,40);
	InsertFirst(&pFirst,&pLast,30);
	InsertFirst(&pFirst,&pLast,20);
	InsertFirst(&pFirst,&pLast,10);
	
	Display(pFirst,pLast);
	
	iCount=CountNodes(pFirst,pLast);
	if(iCount!=0)
		printf("TOTAL NODES=%d\n\n",iCount);
	else
		printf("LINKED LIST IS EMPTY\n\n");
	
	if(pFirst!=NULL)
	{
		DeleteAll(&pFirst,&pLast);
		pFirst=pLast=NULL;
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
		pTemp->pPrev=pTemp->pNext=NULL;
		free(pTemp);
	}
	pTemp=NULL;
	*ppTail=NULL;
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
int CountNodes(struct Node *pHead,struct Node *pTail)
{
	int iCount=0;
	if(NULL==pHead)
		return 0;
	do
	{
		iCount++;
		pHead=pHead->pNext;
	}while(pHead!=(pTail)->pNext);
	return iCount;
}
