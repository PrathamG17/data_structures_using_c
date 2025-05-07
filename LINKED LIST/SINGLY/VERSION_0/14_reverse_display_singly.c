#include<stdio.h>
#include<malloc.h>
struct Node
{
	int iNo;
	struct Node *pNext;
};
void InsertLast(struct Node **,int);
void PhysicalReverse(struct Node **);
void ReverseDisplay(struct Node *);
void DeleteAll(struct Node **);
void Display(struct Node *);
int main(void)
{
	struct Node *pFirst=NULL;
	
	InsertLast(&pFirst,10);
	InsertLast(&pFirst,20);
	InsertLast(&pFirst,30);
	InsertLast(&pFirst,40);
	InsertLast(&pFirst,50);
	
	printf("\n------AFTER INSERTION------\n\n");
	Display(pFirst);
	printf("\n");
	
	printf("\n------REVERSE DISPLAY------\n\n");
	ReverseDisplay(pFirst);
	printf("\n");	
	
	if(pFirst!=NULL)
	{
		DeleteAll(&pFirst);
		pFirst=NULL;
	}
	
	printf("\n------AFTER DELETE ALL------\n\n");
	Display(pFirst);
	printf("\n");
	
	return 0;
}
void InsertLast(struct Node **ppHead,int iData)
{
	struct Node *pNewNode=NULL;
	struct Node *pTemp=NULL;
	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("\nMEMORY ALLOCATION FAILED\n\n");
		return;
	}
	pNewNode->iNo=iData;
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
void PhysicalReverse(struct Node **ppHead)
{
	struct Node *pPrev=NULL;
	struct Node *pCurrent=*ppHead;
	struct Node *pNext=NULL;
	while(pCurrent!=NULL)
	{
		pNext=pCurrent->pNext;
		pCurrent->pNext=pPrev;
		pPrev=pCurrent;
		pCurrent=pNext;
	}
	*ppHead=pPrev;
}
void ReverseDisplay(struct Node *pHead)
{
	if(NULL==pHead)
	{
		printf("\nLIST IS EMPTY\n\n");
		return;
	}
	PhysicalReverse(&pHead);
	Display(pHead);
	PhysicalReverse(&pHead);
}
void Display(struct Node *pHead)
{
	if(NULL==pHead)
	{
		printf("LIST IS EMPTY");
		return;
	}
	while(pHead!=NULL)
	{
		printf("|%d|->",pHead->iNo);
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
