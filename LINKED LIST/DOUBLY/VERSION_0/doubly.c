#include<stdio.h>
#include<malloc.h>
#include "doubly.h"
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
	pNewNode->pPrev=NULL;
	pNewNode->pNext=*ppHead;
	
	if(*ppHead!=NULL)
		(*ppHead)->pPrev=pNewNode;
	
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
		pNewNode->pPrev=pTemp;
	}
	else
	{
		pNewNode->pPrev=NULL;
		*ppHead=pNewNode;
	}
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
	if(iCount+1==iPos)
	{
		InsertLast(ppHead,iData);
		return;
	}
	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("MEMORY ALLOCATION FAILED\n");
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
	pTemp->pNext->pPrev=pNewNode;
	pNewNode->pNext=pTemp->pNext;
	pNewNode->pPrev=pTemp;
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
	if(pTemp->pNext!=NULL)
		pTemp->pNext->pPrev=NULL;
	iDelData=pTemp->iNo;
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
	if(pTemp->pNext!=NULL)
	{
		while(pTemp->pNext->pNext!=NULL)
			pTemp=pTemp->pNext;
		iDelData=pTemp->pNext->iNo;
		pTemp->pNext->pPrev=NULL;
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
	int iCount;
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
	pTemp2->pNext->pPrev=pTemp1;
	iCount=pTemp2->iNo;
	pTemp2->pPrev=pTemp2->pNext=NULL;
	free(pTemp2);
	pTemp2=NULL;
	return iCount;
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
		printf("LIST IS EMPTY\n");
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
	while(pHead->pPrev!=NULL)
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
