#include<stdio.h>
#include<malloc.h>
struct Node
{
	struct Node *pPrev;
	int iNo;
	struct Node *pNext;
};
void Display(struct Node *pHead,struct Node *pTail);
int CountNodes(struct Node *pHead,struct Node *pTail);
void DeleteAll(struct Node **ppHead,struct Node **ppTail);
int DeleteLast(struct Node **ppHead,struct Node **ppTail);
int DeleteFirst(struct Node **ppHead,struct Node **ppTail);
void InsertFirst(struct Node **ppHead,struct Node **ppTail,int iData);
int DeleteAtPosition(struct Node **ppHead,struct Node **ppTail,int iPos);
int main(void)
{	
	int iDelData;
	struct Node *pFirst=NULL;
	struct Node *pLast=NULL;
	
	Display(pFirst,pLast);
	
	InsertFirst(&pFirst,&pLast,50);
	InsertFirst(&pFirst,&pLast,40);
	InsertFirst(&pFirst,&pLast,30);
	InsertFirst(&pFirst,&pLast,20);
	InsertFirst(&pFirst,&pLast,10);

	Display(pFirst,pLast);
	
	iDelData=DeleteAtPosition(&pFirst,&pLast,4);
	if(iDelData!=-1)
		printf("%d IS DELETED\n\n",iDelData);
	else
		printf("DATA NOT FOUND\n\n");
	
	Display(pFirst,pLast);
	
	if(pFirst!=NULL)
	{
		DeleteAll(&pFirst,&pLast);
		pFirst=NULL;
		pLast=NULL;
	}
	
	Display(pFirst,pLast);
	
	return 0;
}
void Display(struct Node *pHead,struct Node *pTail)
{
	if(NULL==pHead)
	{
		printf("LINKED LIST IS EMPTY\n\n");
		return;
	}
	do
	{
		printf("|%d|->",pHead->iNo);
		pHead=pHead->pNext;
	}while(pHead!=pTail->pNext);
	printf("\n\n");
}
void DeleteAll(struct Node **ppHead,struct Node **ppTail)
{
	struct Node *pTemp=NULL;
	(*ppTail)->pNext=NULL;
	while(*ppHead!=NULL)
	{
		pTemp=*ppHead;
		*ppHead=pTemp->pNext;
		pTemp->pNext=NULL;
		free(pTemp);
	}
	pTemp=NULL;
	*ppHead=NULL;
}
void InsertFirst(struct Node **ppHead,struct Node **ppTail,int iData)
{
	struct Node *pNewNode=NULL;
	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("MEMORY ALLOCATION FAILED\n\n");
		return;
	}
	pNewNode->iNo=iData;
	if(NULL==*ppHead)
		*ppHead=*ppTail=pNewNode;
	else
	{	pNewNode->pNext=*ppHead;
		*ppHead=pNewNode;
	}
	(*ppTail)->pNext=*ppHead;							//CIRCULAR EFFECT
}
int DeleteFirst(struct Node **ppHead,struct Node **ppTail)
{
	int iDelData;
	if(NULL==*ppHead)
		return -1;
	iDelData=(*ppHead)->iNo;
	if(*ppHead==*ppTail)
	{
		(*ppHead)->pPrev=(*ppHead)->pNext=NULL;
		free(*ppHead);
		*ppHead=*ppTail=NULL;
	}
	else
	{
		*ppHead=(*ppHead)->pNext;
		(*ppTail)->pNext->pPrev=(*ppTail)->pNext->pNext=NULL;
		free((*ppTail)->pNext);
		(*ppHead)->pPrev=*ppTail;
		(*ppTail)->pNext=*ppHead;
	}
	return iDelData;
}
int DeleteLast(struct Node **ppHead,struct Node **ppTail)
{
	int iDelData;
	if(NULL==*ppHead)
		return -1;
	iDelData=(*ppTail)->iNo;
	if(*ppHead==*ppTail)
	{
		(*ppTail)->pPrev=(*ppTail)->pNext=NULL;
		free(*ppTail);
		*ppHead=*ppTail=NULL;
	}
	else
	{
		*ppTail=(*ppTail)->pPrev;
		(*ppTail)->pNext->pPrev=(*ppTail)->pNext->pNext=NULL;
		free((*ppTail)->pNext);
		(*ppHead)->pPrev=*ppTail;
		(*ppTail)->pNext=*ppHead;						//CIRCULAR EFFECT
	}
	return iDelData;
}
int CountNodes(struct Node *pHead,struct Node *pTail)
{
	int iCount=0;
	if(NULL==pHead)
		return 0;
	do
	{
		iCount++;
		pHead=pHead->pNext;
	}while(pHead!=(pTail)->pNext);
	return iCount;
}
int DeleteAtPosition(struct Node **ppHead,struct Node **ppTail,int iPos)
{
	int iCount=0;
	struct Node *pTemp=NULL;
	if(iPos<=0||iPos>(iCount=CountNodes(*ppHead,*ppTail)))
	{
		printf("INVALID POSITION\n\n");
		return -1;
	}
	if(1==iPos)
		return DeleteFirst(ppHead,ppTail);
	if(iPos==iCount)
		return DeleteLast(ppHead,ppTail);
	pTemp=*ppHead;
	iCount=1;
	while(iCount<iPos-1)
	{
		iCount++;
		pTemp=pTemp->pNext;
	}
	iCount=pTemp->pNext->iNo;
	pTemp->pNext=pTemp->pNext->pNext;
	pTemp->pNext->pPrev=pTemp->pNext->pNext=NULL;
	free(pTemp->pNext->pPrev);
	pTemp->pNext->pPrev=pTemp;
	return iCount;
}
