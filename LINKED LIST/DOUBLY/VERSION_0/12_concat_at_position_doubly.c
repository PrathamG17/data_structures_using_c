#include<stdio.h>
#include<malloc.h>
struct Node 
{
	struct Node *pPrev;
	int iNo;
	struct Node *pNext;
};
void InsertFirst(struct Node **,int);
void ConcatAtPosition(struct Node **,struct Node **,int);
void ConcatList(struct Node **,struct Node **);
int CountNodes(struct Node *);
void DeleteAll(struct Node **);
void Display(struct Node *);
int main(void)
{
	struct Node *pFirst1=NULL;
	struct Node *pFirst2=NULL;
	
	InsertFirst(&pFirst1,30);
	InsertFirst(&pFirst1,20);
	InsertFirst(&pFirst1,10);

	InsertFirst(&pFirst2,60);
	InsertFirst(&pFirst2,50);
	InsertFirst(&pFirst2,40);

	printf("\n------AFTER INSERTION------\n");
	printf("\nLINKED LIST 1 IS...\n\n");
	Display(pFirst1);
	printf("\n");
	printf("\nLINKED LIST 2 IS...\n\n");
	Display(pFirst2);
	printf("\n");
	
	ConcatAtPosition(&pFirst1,&pFirst2,3);
	
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
void ConcatAtPosition(struct Node **ppHead1,struct Node **ppHead2,int iPos)
{
	struct Node *pTemp1=NULL;
	struct Node *pTemp2=NULL;
	int iCount;
	iCount=CountNodes(*ppHead1);
	if(iPos<=0||iPos>iCount+1)
	{
		printf("\nINVALID POSITION\n\n");
		return;
	}
	if(NULL==*ppHead2)
		return;
	if(1==iPos)
	{
		*ppHead1=*ppHead2;
		*ppHead2=NULL;
		return;
	}
	if(iPos==iCount+1)
	{
		ConcatList(ppHead1,ppHead2);
		return;
	}
	pTemp1=*ppHead1;
	iCount=1;
	while(iCount<iPos-1)
	{
		iCount++;
		pTemp1=pTemp1->pNext;
	}
	pTemp2=*ppHead2;
	while(pTemp2->pNext!=NULL)
		pTemp2=pTemp2->pNext;
	pTemp2->pNext=pTemp1->pNext;
	pTemp1->pNext->pPrev=pTemp2;
	pTemp1->pNext=*ppHead2;
	(*ppHead2)->pPrev=pTemp1;
	*ppHead2=NULL;
}
void ConcatList(struct Node **ppHead1,struct Node **ppHead2)
{
	struct Node *pTemp=NULL;
	if(NULL==*ppHead2)
		return;
	if(NULL==*ppHead1)
	{
		*ppHead1=*ppHead2;
		*ppHead2=NULL;
		return;
	}
	pTemp=*ppHead1;
	while(pTemp->pNext!=NULL)
		pTemp=pTemp->pNext;
	pTemp->pNext=*ppHead2;
	(*ppHead2)->pPrev=pTemp;
	*ppHead2=NULL;
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
