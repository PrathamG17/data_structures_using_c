#include<stdio.h>
#include<malloc.h>
struct Node
{
	struct Node *pPrev;
	int iNo;
	struct Node *pNext;
};
void InsertFirst(struct Node **,int);
void Display(struct Node *);
int DeleteFirst(struct Node **);
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
	
	iDelData=DeleteFirst(&pFirst);
	if(iDelData!=-1)
		printf("\n%d IS DELETED.\n",iDelData);
	else
		printf("\nLIST IS EMPTY.\n");
	
	printf("\n------AFTER DELETE------\n\n");
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
	pNewNode->pPrev=NULL;
	pNewNode->pNext=*ppHead;
	if(*ppHead!=NULL)
		(*ppHead)->pPrev=pNewNode;
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
int DeleteFirst(struct Node **ppHead)
{
	int iDelData;
	if(NULL==*ppHead)
		return -1;
	iDelData=(*ppHead)->iNo;
	if((*ppHead)->pNext==NULL)
	{
		free(*ppHead);
		*ppHead=NULL;
	}
	else
	{
		*ppHead=(*ppHead)->pNext;
		(*ppHead)->pPrev->pNext=NULL;
		free((*ppHead)->pPrev);
		(*ppHead)->pPrev=NULL;
	}
	return iDelData;
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
