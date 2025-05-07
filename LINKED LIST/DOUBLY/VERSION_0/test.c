#include<stdio.h>
#include<malloc.h>
#include "..\VERSION_1\doubly.h"

// struct Node
// {
	// struct Node *pPrev;
	// int iNo;
	// struct Node *pNext;
// };
/*
void InsertFirst(struct Node **,int);
void PhysicalReverse(struct Node **);
void DeleteAll(struct Node **);
void Display(struct Node *);
*/
int main(void)
{
	struct Node *pFirst=NULL;
	
	InsertFirst(&pFirst,50);
	InsertFirst(&pFirst,20);
	InsertFirst(&pFirst,30);
	InsertFirst(&pFirst,20);
	//InsertFirst(&pFirst,10);
	
	printf("\n------AFTER INSERTION------\n\n");
	Display(pFirst);
	printf("\n");
	
	PhysicalReverse(&pFirst);
	
	printf("\n------AFTER REVERSE------\n\n");
	Display(pFirst);
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
/*
void InsertFirst(struct Node **ppHead,int iData)
{
	struct Node *pNewNode=NULL;
	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("\nMEMORY ALLOCATION FAILED\n\n");
		return;
	}
	pNewNode->iNo=iData;
	pNewNode->pPrev=NULL;
	pNewNode->pNext=*ppHead;
	if(*ppHead!=NULL)
		(*ppHead)->pPrev=pNewNode;
	*ppHead=pNewNode;
}
void PhysicalReverse(struct Node **ppHead)
{
	struct Node *pCurrent=*ppHead;
	struct Node *pNext=NULL;
	while(pCurrent!=NULL)
	{
		pNext=pCurrent->pNext;
		pCurrent->pNext=pCurrent->pPrev;
		pCurrent->pPrev=pNext;
		if(NULL==pNext)
			*ppHead=pCurrent;
		pCurrent=pNext;
	}
}
void DeleteAll(struct Node **ppHead)
{
	struct Node *pTemp=NULL;
	while(*ppHead!=NULL)
	{
		pTemp=*ppHead;
		*ppHead=pTemp->pNext;
		pTemp->pPrev=pTemp->pNext=NULL;
		free(pTemp);
	}
	pTemp=NULL;
}
void Display(struct Node *pHead)
{
	if(NULL==pHead)
	{
		printf("LIST IS EMPTY\n");
		return;
	}
	while(pHead!=NULL)
	{
		printf("|%d|->",pHead->iNo);
		pHead=pHead->pNext;
	}
}*/