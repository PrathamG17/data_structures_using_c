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
int CountNodes(struct Node *);
int DeleteAtPosition(struct Node **,int);
int DeleteFirst(struct Node **);
void DeleteAll(struct Node **);
int main(void)
{
	int iDelData;
	struct Node *pFirst=NULL;
	
	printf("\n");
	Display(pFirst);
	printf("\n");
	
	InsertFirst(&pFirst,50);
	InsertFirst(&pFirst,40);
	InsertFirst(&pFirst,30);
	InsertFirst(&pFirst,20);
	InsertFirst(&pFirst,10);
	
	printf("\n------AFTER INSERTION------\n\n");
	Display(pFirst);
	printf("\n");
	
	iDelData=DeleteAtPosition(&pFirst,3);
	if(iDelData!=-1)
		printf("\nDATA %d DELETED FROM NODE %d.\n",iDelData,3);
	else
		printf("\nLINKED LIST IS EMPTY.\n\n");

	printf("\n------AFTER DELETE------\n\n");
	Display(pFirst);
	printf("\n");
	
	iDelData=DeleteAtPosition(&pFirst,2);
	if(iDelData!=-1)
		printf("\nDATA %d DELETED FROM NODE %d.\n",iDelData,2);
	else
		printf("\nLINKED LIST IS EMPTY.\n\n");

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
		printf("\nMEMORY ALLOCATION FAILED.\n\n");
		return;
	}
	pNewNode->iNo=iData;
	pNewNode->pPrev=NULL;
	pNewNode->pNext=*ppHead;
	if(*ppHead!=NULL)
		(*ppHead)->pPrev=pNewNode;
	*ppHead=pNewNode;
}
int DeleteAtPosition(struct Node **ppHead,int iPos)
{
	int iCount;
	struct Node *pTemp=NULL;
	iCount=CountNodes(*ppHead);
	if(iPos<=0||iPos>iCount)
	{
		printf("\nINVALID POSITION.\n\n");
		return -1;
	}
	if(1==iPos)
		return DeleteFirst(ppHead);
	pTemp=*ppHead;
	iCount=1;
	while(iCount<iPos)
	{
		iCount++;
		pTemp=pTemp->pNext;
	}
	iCount=pTemp->iNo;
	pTemp->pPrev->pNext=pTemp->pNext;
	if(pTemp->pNext!=NULL)
		pTemp->pNext->pPrev=pTemp->pPrev;
	pTemp->pPrev=pTemp->pNext=NULL;
	free(pTemp);
	pTemp=NULL;
	return iCount;
}
int DeleteFirst(struct Node **ppHead)
{
	int iDelData;
	if(NULL==*ppHead)
		return -1;
	iDelData=(*ppHead)->iNo;
	if(NULL==(*ppHead)->pNext)
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
void Display(struct Node *pHead)
{
	if(NULL==pHead)
	{
		printf("LIST IS EMPTY.");
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
