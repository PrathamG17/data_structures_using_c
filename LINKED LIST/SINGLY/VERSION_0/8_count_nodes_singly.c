#include<stdio.h>
#include<malloc.h>
struct Node 
{
	int iNo;
	struct Node *pNext;
};
void InsertLast(struct Node **,int);
void Display(struct Node *);
int CountNodes(struct Node *);
void DeleteAll(struct Node **);
int main(void)
{
	int iCount;
	struct Node *pFirst=NULL;
	
	iCount=CountNodes(pFirst);
	printf("\n------BEFORE INSERTION------\n");
	if(iCount!=0)
		printf("\nEXISTING LINKED LIST IS OF %d NODES.\n\n",iCount);
	else
		printf("\nLINKED LIST IS EMPTY.\n\n");
	
	InsertLast(&pFirst,10);
	InsertLast(&pFirst,20);
	InsertLast(&pFirst,30);
	InsertLast(&pFirst,40);
	InsertLast(&pFirst,50);
	
	printf("\n------AFTER INSERTION------\n\n");
	Display(pFirst);
	printf("\n");
	
	iCount=CountNodes(pFirst);
	if(iCount!=0)
		printf("\nEXISTING LINKED LIST IS OF %d NODES.\n\n",iCount);
	else
		printf("\nLINKED LIST IS EMPTY.\n\n");
	
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
	struct Node *pNewNode=NULL,*pTemp=NULL;
	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("\nMEMORY ALLOCATION FAILED\n");
		return;
	}
	pNewNode->iNo=iData;
	pNewNode->pNext=NULL;
	if(NULL==*ppHead)
		*ppHead=pNewNode;
	else
	{
		pTemp=*ppHead;
		while(pTemp->pNext!=NULL)
			pTemp=pTemp->pNext;
		pTemp->pNext=pNewNode;
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
int CountNodes(struct Node *pHead)
{
	int iCount1=0;
	while(pHead!=NULL)
	{
		iCount1++;
		pHead=pHead->pNext;
	}
	return iCount1;
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
