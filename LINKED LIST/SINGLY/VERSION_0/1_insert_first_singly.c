#include<stdio.h>
#include<malloc.h>
struct Node
{
	int iNo;
	struct Node *pNext;
};
void InsertFirst(struct Node **,int);
void Display(struct Node *);
void DeleteAll(struct Node **);
int main(void)
{
	struct Node *pFirst=NULL;
	
	printf("\n");
	Display(pFirst);
	printf("\n");
	
	InsertFirst(&pFirst,10);
	InsertFirst(&pFirst,20);
	InsertFirst(&pFirst,30);
	
	printf("\n------AFTER INSERTION------\n\n");
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
void InsertFirst(struct Node **ppHead,int iData)
{
	struct Node *pNewNode=NULL;
	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("\nMEMORY ALLOCATION FAILED\n");
		return;
	}
	pNewNode->iNo=iData;
	if(*ppHead!=NULL)
		pNewNode->pNext=*ppHead;
	else
		pNewNode->pNext=NULL;
	*ppHead=pNewNode;
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
