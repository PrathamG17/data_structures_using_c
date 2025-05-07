#include<stdio.h>
#include<malloc.h>
struct Node
{
	int iNo;
	struct Node *pNext;
};
void InsertFirst(struct Node **,int);
int DeleteLast(struct Node **);
void Display(struct Node *);
void DeleteAll(struct Node **);
int main(void)
{
	int iDelData;
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
	
	iDelData=DeleteLast(&pFirst);
	if(iDelData!=-1)
		printf("\n%d IS DELETED\n",iDelData);
	
	printf("\n------AFTER DELETE LAST------\n\n");
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
	pNewNode->pNext=*ppHead;
	*ppHead=pNewNode;
}
int DeleteLast(struct Node **ppHead)
{
	int iData;
	struct Node *pTemp=NULL;
	if(NULL==*ppHead)
	{
		printf("\nLIST IS EMPTY\n");
		return -1;
	}
	pTemp=*ppHead;
	if(NULL==pTemp->pNext)
	{
		iData=pTemp->iNo;
		free(pTemp);
		*ppHead=NULL;
		pTemp=NULL;
	}
	else
	{
		while(pTemp->pNext->pNext!=NULL)
			pTemp=pTemp->pNext;
		iData=pTemp->pNext->iNo;
		free(pTemp->pNext);
		pTemp->pNext=NULL;
	}
	return iData;
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