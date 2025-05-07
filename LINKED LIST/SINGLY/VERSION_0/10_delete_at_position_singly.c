#include<stdio.h>
#include<malloc.h>
struct Node
{
	int iNo;
	struct Node *pNext;
};
void InsertFirst(struct Node **,int);
void Display(struct Node *);
int DeleteAtPosition(struct Node **,int);
int DeleteFirst(struct Node **);
int DeleteLast(struct Node **);
int CountNode(struct Node *);
void DeleteAll(struct Node **);
int main(void)
{
	int iDelData;
	struct Node *pFirst=NULL;
	
	InsertFirst(&pFirst,10);
	InsertFirst(&pFirst,20);
	InsertFirst(&pFirst,30);
	InsertFirst(&pFirst,40);
	InsertFirst(&pFirst,50);
	
	printf("\n------AFTER INSERTION------\n\n");
	Display(pFirst);
	printf("\n");
	
	iDelData=DeleteAtPosition(&pFirst,2);
	if(iDelData!=-1)
		printf("\nDATA %d IS DELETED FROM NODE %d\n",iDelData,2);

	printf("\n------AFTER DELETE------\n\n");
	Display(pFirst);
	printf("\n");
	
	iDelData=DeleteAtPosition(&pFirst,3);
	if(iDelData!=-1)
		printf("\nDATA %d IS DELETED FROM NODE %d\n",iDelData,3);
	
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
		printf("\nMEMORY ALLOCATION FAILED\n\n");
		return;
	}
	pNewNode->iNo=iData;
	pNewNode->pNext=*ppHead;
	*ppHead=pNewNode;
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
int DeleteAtPosition(struct Node **ppHead,int iPos)
{
	int iCount,iDelData;
	struct Node *pTemp1=NULL,*pTemp2=NULL;
	iCount=CountNode(*ppHead);
	if(iPos<=0||iPos>iCount+1)
	{
		printf("\nINVALID POSITION\n\n");
		return -1;
	}
	if(1==iPos)
	{
		iDelData=DeleteFirst(ppHead);
		return iDelData;
	}
	if(iPos==iCount+1)
	{
		iDelData=DeleteLast(ppHead);
		return iDelData;
	}
	pTemp1=*ppHead;
	iCount=1;
	while(iCount<iPos-1)
	{
		iCount++;
		pTemp1=pTemp1->pNext;
	}
	pTemp2=pTemp1->pNext;
	iDelData=pTemp2->iNo;
	pTemp1->pNext=pTemp2->pNext;
	pTemp2->pNext=NULL;
	free(pTemp2);
	pTemp2=NULL;
	return iDelData;
}
int DeleteFirst(struct Node **ppHead)
{
	int iDelData;
	struct Node *pTemp=NULL;
	if(NULL==*ppHead)
		return -1;
	pTemp=*ppHead;
	iDelData=pTemp->iNo;
	*ppHead=pTemp->pNext;
	pTemp->pNext=NULL;
	free(pTemp);
	pTemp=NULL;
	return iDelData;
}
int DeleteLast(struct Node **ppHead)
{
	int iDelData;
	struct Node *pTemp=NULL;
	if(NULL==*ppHead)
		return -1;
	pTemp=*ppHead;
	if(NULL==pTemp->pNext)
	{
		iDelData=pTemp->iNo;
		free(pTemp);
		pTemp=NULL;
		*ppHead=NULL;
	}
	else
	{
		while(pTemp->pNext->pNext!=NULL)
			pTemp=pTemp->pNext;
		iDelData=pTemp->pNext->iNo;
		free(pTemp->pNext);
		pTemp->pNext=NULL;
	}
	return iDelData;
}
int CountNode(struct Node *pHead)
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
		pTemp->pNext=NULL;
		free(pTemp);
	}
	pTemp=NULL;
}
