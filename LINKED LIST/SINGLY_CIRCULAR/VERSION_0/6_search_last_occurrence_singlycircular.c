#include<stdio.h>
#include<malloc.h>
struct Node
{
	int iNo;
	struct Node *pNext;
};
void Display(struct Node *pHead,struct Node *pTail);
void DeleteAll(struct Node **ppHead,struct Node **ppTail);
void InsertFirst(struct Node **ppHead,struct Node **ppTail,int iData);
int SearchLastOccurrence(struct Node *pHead,struct Node *pTail,int iKey);
int main(void)
{	
	int iPos;
	struct Node *pFirst=NULL;
	struct Node *pLast=NULL;
	
	Display(pFirst,pLast);
	
	InsertFirst(&pFirst,&pLast,30);
	InsertFirst(&pFirst,&pLast,40);
	InsertFirst(&pFirst,&pLast,30);
	InsertFirst(&pFirst,&pLast,20);
	InsertFirst(&pFirst,&pLast,10);

	Display(pFirst,pLast);
	
	iPos=SearchLastOccurrence(pFirst,pLast,30);
	if(iPos!=0)
		printf("DATA %d FOUND LAST IN NODE %d\n\n",30,iPos);
	else
		printf("DATA NOT FOUND\n\n");
	
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
	{	pNewNode->pNext=*ppHead;
		*ppHead=pNewNode;
	}
	(*ppTail)->pNext=*ppHead;							//CIRCULAR EFFECT
}
int SearchLastOccurrence(struct Node *pHead,struct Node *pTail,int iKey)
{
	int iCount=0;
	int iLastPos=0;
	do
	{
		iCount++;
		if(pHead->iNo==iKey)
			iLastPos=iCount;
		pHead=pHead->pNext;
	}while(pHead!=(pTail)->pNext);
	return iLastPos;
}
