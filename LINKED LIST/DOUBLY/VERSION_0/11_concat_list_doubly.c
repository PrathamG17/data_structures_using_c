#include<stdio.h>
#include<malloc.h>
struct Node
{
	struct Node *pPrev;
	int iNo;
	struct Node *pNext;
};
void InsertLast(struct Node **,int);
void ConcatList(struct Node **,struct Node **);
void DeleteAll(struct Node **);
void Display(struct Node *);
void DeleteAll(struct Node **);
int main(void)
{
	struct Node *pFirst1=NULL;
	struct Node *pFirst2=NULL;

	InsertLast(&pFirst1,10);
	InsertLast(&pFirst1,20);
	InsertLast(&pFirst1,30);
	
	InsertLast(&pFirst2,40);
	InsertLast(&pFirst2,50);
	InsertLast(&pFirst2,60);
	
	printf("\n------AFTER INSERTION------\n");
	printf("\nLINKED LIST 1 IS...\n\n");
	Display(pFirst1);
	printf("\n");
	printf("\nLINKED LIST 2 IS...\n\n");
	Display(pFirst2);
	printf("\n");
	
	ConcatList(&pFirst1,&pFirst2);
	
	printf("\n------AFTER CONCATENATION-------\n");
	printf("\nLINKED LIST 1 IS...\n\n");
	Display(pFirst1);
	printf("\n");
	printf("\nLINKED LIST 2 IS...\n\n");
	Display(pFirst2);
	printf("\n");
	
	if(pFirst1!=NULL)
	{
		DeleteAll(&pFirst1);
		pFirst1=NULL;
	}
	
	if(pFirst2!=NULL)
	{
		DeleteAll(&pFirst2);
		pFirst2=NULL;
	}
	
	printf("\n-------AFTER DELETE ALL--------\n");
	printf("\nLINKED LIST 1 IS...\n\n");
	Display(pFirst1);
	printf("\n");
	printf("\nLINKED LIST 2 IS...\n\n");
	Display(pFirst2);
	printf("\n");
	
	return 0;
}
void InsertLast(struct Node **ppHead,int iData)
{
	struct Node *pTemp=NULL;
	struct Node *pNewNode=NULL;
	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("\nMEMORY ALLOCATION FAILED\n");
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
void ConcatList(struct Node **ppHead1,struct Node **ppHead2)
{
	struct Node *pTemp=NULL;
	if(NULL==*ppHead2)
		return;
	if(NULL==*ppHead1)
		*ppHead1=*ppHead2;
	else
	{
		pTemp=*ppHead1;
		while(pTemp->pNext!=NULL)
			pTemp=pTemp->pNext;
		pTemp->pNext=*ppHead2;
		(*ppHead2)->pPrev=pTemp;
	}
	*ppHead2=NULL;
}
void DeleteAll(struct Node **ppHead)
{
	struct Node *pTemp=NULL;
	while(*ppHead!=NULL)
	{
		pTemp=*ppHead;
		*ppHead=pTemp->pNext;
		pTemp->pNext=pTemp->pPrev=NULL;
		free(pTemp);
	}
	pTemp=NULL;
}
void Display(struct Node *pHead)
{
	if(NULL==pHead)
	{
		printf("LINKED LIST IS EMPTY");
		return;
	}
	while(pHead!=NULL)
	{
		printf("|%d|->",pHead->iNo);
		pHead=pHead->pNext;
	}
}
