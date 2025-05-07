#include<stdio.h>
#include<malloc.h>
#include"singly.h"
void InsertFirst(struct Node **ppHead,int iData)
{
	struct Node *pNewNode=NULL;
	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("MEMORY ALLOCATION FAILED\n");
		return;
	}
	pNewNode->iNo=iData;
	pNewNode->pNext=*ppHead;
	*ppHead=pNewNode;
}
void InsertLast(struct Node **ppHead,int iData)
{
	struct Node *pNewNode=NULL;
	struct Node *pTemp=NULL;
	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("MEMORY ALLOCATION FAILED\n");
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
	}
	else
		*ppHead=pNewNode;
}
void InsertAtPosition(struct Node **ppHead,int iData,int iPos)
{
	int iCount;
	struct Node *pNewNode=NULL;
	struct Node *pTemp=NULL;
	iCount=CountNodes(*ppHead);
	if(iPos<=0||iPos>iCount+1)
		return;
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
		printf("MEMROY ALLOCATION FAILED\n");
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
	pTemp->pNext=pNewNode;
}
int DeleteFirst(struct Node **ppHead)
{
	int iDelData;
	struct Node *pTemp=NULL;
	if(NULL==*ppHead)
		return -1;
	pTemp=*ppHead;
	*ppHead=pTemp->pNext;
	iDelData=pTemp->iNo;
	pTemp->pNext=NULL;
	free(pTemp);
	return iDelData;
}
int DeleteLast(struct Node **ppHead)
{
	int iDelData;
	struct Node *pTemp=NULL;
	if(NULL==*ppHead)
		return -1;
	pTemp=*ppHead;
	if(pTemp->pNext!=NULL)
	{
		while(pTemp->pNext->pNext!=NULL)
			pTemp=pTemp->pNext;
		iDelData=pTemp->pNext->iNo;
		free(pTemp->pNext);
		pTemp->pNext=NULL;
	}
	else
	{
		iDelData=pTemp->iNo;
		free(pTemp);
		pTemp=NULL;
		*ppHead=NULL;
	}
	return iDelData;
}
int DeleteAtPosition(struct Node **ppHead,int iPos)
{
	int iDelData,iCount;
	struct Node *pTemp1=NULL;
	struct Node *pTemp2=NULL;
	iCount=CountNodes(*ppHead);
	if(iPos<=0||iPos>iCount)
		return -1;
	if(1==iPos)
		return DeleteFirst(ppHead);
	if(iCount==iPos)
		return DeleteLast(ppHead);
	pTemp1=*ppHead;
	iCount=1;
	while(iCount<iPos-1)
	{
		iCount++;
		pTemp1=pTemp1->pNext;
	}
	pTemp2=pTemp1->pNext;
	pTemp1->pNext=pTemp2->pNext;
	iDelData=pTemp2->iNo;
	pTemp2->pNext=NULL;
	free(pTemp2);
	pTemp2=NULL;
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
		printf("LINKED LIST IS EMPTY");
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
		if(pHead->iNo==iKey)
			return iCount;
		pHead=pHead->pNext;
	}
	return 0;
}
int SearchLastOccurrence(struct Node *pHead,int iKey)
{
	int iCount=0;
	int iLastPos=0;
	while(pHead!=NULL)
	{
		iCount++;
		if(pHead->iNo==iKey)
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
		if(pHead->iNo==iKey)
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
	*ppHead2=NULL;
}
void ConcatAtPosition(struct Node **ppHead1,struct Node **ppHead2,int iPos)
{
	int iCount;
	struct Node *pTemp1=NULL;
	struct Node *pTemp2=NULL;
	iCount=CountNodes(*ppHead1);
	if(iPos<=0||iPos>iCount+1)
		return;
	if(NULL==*ppHead2)
		return;
	if(1==iPos)
	{
		ConcatList(ppHead2,ppHead1);
		*ppHead1=*ppHead2;
		*ppHead2=NULL;
		return;
	}
	if(iCount+1==iPos)
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
	pTemp1->pNext=*ppHead2;
	*ppHead2=NULL;
}
void PhysicalReverse(struct Node **ppHead)
{
	struct Node *pPrev=NULL;
	struct Node *pCurrent=*ppHead;
	struct Node *pNext=NULL;
	while(pCurrent!=NULL)
	{
		pNext=pCurrent->pNext;
		pCurrent->pNext=pPrev;
		pPrev=pCurrent;
		pCurrent=pNext;
	}
	*ppHead=pPrev;
}
void ReverseDisplay(struct Node *pHead)
{
	PhysicalReverse(&pHead);
	Display(pHead);
	PhysicalReverse(&pHead);
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
