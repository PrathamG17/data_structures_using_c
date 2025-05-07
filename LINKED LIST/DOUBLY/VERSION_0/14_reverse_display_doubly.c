#include<stdio.h>
#include<malloc.h>
struct Node 
{
	struct Node *pPrev;
	int iNo;
	struct Node *pNext;
};
void InsertLast(struct Node **,int);
void ReverseDisplay(struct Node *);
void Display(struct Node *);
void DeleteAll(struct Node **);
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
	
	printf("\n------REVERSE------\n\n");
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
		pNewNode->pPrev=pTemp;
	}
	else
	{
		*ppHead=pNewNode;
		pNewNode->pPrev=NULL;
	}
}
void ReverseDisplay(struct Node *pHead)
{
	if(NULL==pHead)
	{
		printf("\nLIST IS EMPTY\n\n");
		return;
	}
	while(pHead->pNext!=NULL)
		pHead=pHead->pNext;
	while(pHead!=NULL)
	{
		printf("|%d|->",pHead->iNo);
		pHead=pHead->pPrev;
	}
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
		pTemp->pPrev=pTemp->pNext=NULL;
		free(pTemp);
	}
	pTemp=NULL;
}
