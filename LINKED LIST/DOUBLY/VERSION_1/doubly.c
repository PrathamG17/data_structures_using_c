#include<stdio.h>
#include<malloc.h>
#include"doubly.h"
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
	if(NULL==*ppHead)
		*ppHead=pNewNode;
	else
	{
		(*ppHead)->pPrev=pNewNode;
		*ppHead=pNewNode;
	}
}
void InsertLast(struct Node **ppHead,int iData)
{
	struct Node *pNewNode=NULL,*pTemp=NULL;
	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("\nMEMORY ALLOCATION FAILED\n\n");
		return;
	}
	pNewNode->iNo=iData;
	pNewNode->pNext=NULL;
	if(NULL==*ppHead)
	{
		pNewNode->pPrev=NULL;
		*ppHead=pNewNode;
	}
	else
	{
		pTemp=*ppHead;
		while(pTemp->pNext!=NULL)
			pTemp=pTemp->pNext;
		pNewNode->pPrev=pTemp;
		pTemp->pNext=pNewNode;
	}
}
void InsertAtPosition(struct Node **ppHead,int iData,int iPos)
{
	int iCount;
	struct Node *pNewNode=NULL,*pTemp=NULL;
	iCount=CountNodes(*ppHead);
	if(iPos<=0||iPos>iCount+1)
	{
		printf("\nINVALID POSITION\n\n");
		return;
	}
	if(1==iPos)
	{
		InsertFirst(ppHead,iData);
		return;
	}
	if(iPos==iCount+1)
	{
		InsertLast(ppHead,iData);
		return;
	}
	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("\nMEMORY ALLOCATION FAILED\n\n");
		return;
	}
	pNewNode->iNo=iData;
	pTemp=*ppHead;
	iCount=1;
	while(iCount<iPos-1)
	{
		iCount++;
		pTemp=pTemp->pNext;
	}
	pNewNode->pNext=pTemp->pNext;
	pNewNode->pNext->pPrev=pNewNode;
	pTemp->pNext=pNewNode;
	pNewNode->pPrev=pTemp;
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
int DeleteLast(struct Node **ppHead)
{
	int iDelData;
	struct Node *pTemp=NULL;
	if(NULL==*ppHead)
		return -1;
	pTemp=*ppHead;
	while(pTemp->pNext!=NULL)
		pTemp=pTemp->pNext;
	iDelData=pTemp->iNo;
	if(NULL==pTemp->pPrev)
		*ppHead=NULL;
	else
	{
		pTemp->pPrev->pNext=NULL;
		pTemp->pPrev=NULL;
	}
	free(pTemp);
	pTemp=NULL;
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
		printf("LIST IS EMPTY");
		return;
	}
	while(pHead!=NULL)
	{
		printf("|%d|->",pHead->iNo);
		pHead=pHead->pNext;
	}
}
int SearchFirstOccurrence(struct Node *pHead,int iKey)
{
	int iCount=0;
	while(pHead!=NULL)
	{
		iCount++;
		if(iKey==pHead->iNo)
			return iCount;
		pHead=pHead->pNext;
	}
	return 0;
}
int SearchLastOccurrence(struct Node *pHead,int iKey)
{
	int iCount=0,iLastPos=0;
	while(pHead!=NULL)
	{
		iCount++;
		if(iKey==pHead->iNo)
			iLastPos=iCount;
		pHead=pHead->pNext;
	}
	return iLastPos;
}
int SearchAllOccurrence(struct Node *pHead,int iKey)
{
	int iCount=0;
	while(pHead!=NULL)
	{
		if(iKey==pHead->iNo)
			iCount++;
		pHead=pHead->pNext;
	}
	return iCount;
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
void ReverseDisplay(struct Node *pHead)
{
	if(NULL==pHead)
	{
		printf("LIST IS EMPTY\n");
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
