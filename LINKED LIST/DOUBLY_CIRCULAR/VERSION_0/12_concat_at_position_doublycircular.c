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
void ConcatList(struct Node **ppHead1,struct Node **ppTail1,
				struct Node **ppHead2,struct Node **ppTail2);
void InsertFirst(struct Node **ppHead,struct Node **ppTail,int iData);
void ConcatAtPosition(struct Node **ppHead1,struct Node **ppTail1,
					  struct Node **ppHead2,struct Node **ppTail2,int iPos);
int main(void)
{
	struct Node *pFirst1=NULL;
	struct Node *pLast1=NULL;
	struct Node *pFirst2=NULL;
	struct Node *pLast2=NULL;
	
	Display(pFirst1,pLast1);
	Display(pFirst2,pLast2);
	
	InsertFirst(&pFirst1,&pLast1,50);
	InsertFirst(&pFirst1,&pLast1,40);
	InsertFirst(&pFirst1,&pLast1,30);
	InsertFirst(&pFirst1,&pLast1,20);
	InsertFirst(&pFirst1,&pLast1,10);

	Display(pFirst1,pLast1);

	InsertFirst(&pFirst2,&pLast2,100);
	InsertFirst(&pFirst2,&pLast2,90);
	InsertFirst(&pFirst2,&pLast2,80);
	InsertFirst(&pFirst2,&pLast2,70);
	InsertFirst(&pFirst2,&pLast2,60);
	
	Display(pFirst2,pLast2);
	
	ConcatAtPosition(&pFirst1,&pLast1,&pFirst2,&pLast2,4);

	Display(pFirst1,pLast1);
	
	if(pFirst1!=NULL)
	{
		DeleteAll(&pFirst1,&pLast1);
		pFirst1=NULL;
		pLast1=NULL;
	}

	if(pFirst2!=NULL)
	{
		DeleteAll(&pFirst2,&pLast2);
		pFirst2=NULL;
		pLast2=NULL;
	}
	
	Display(pFirst1,pLast1);
	Display(pFirst2,pLast2);
	
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
	{
		pNewNode->pNext=*ppHead;
		(*ppHead)->pPrev=pNewNode;
		*ppHead=pNewNode;
	}
	(*ppHead)->pPrev=*ppTail;
	(*ppTail)->pNext=*ppHead;						//CIRCULAR EFFECT				
}
void ConcatList(struct Node **ppHead1,struct Node **ppTail1,
				struct Node **ppHead2,struct Node **ppTail2)
{
	if(NULL==*ppHead2)
		return;
	if(NULL==*ppHead1)
	{
		*ppHead1=*ppHead2;
		*ppTail1=*ppTail2;
		*ppHead2=*ppTail2=NULL;
		return;
	}
	(*ppTail1)->pNext=*ppHead2;
	(*ppHead2)->pPrev=*ppTail1;						//-----------------------------(1)
	*ppTail1=*ppTail2;
	(*ppHead1)->pPrev=*ppTail1;						//-----------------------------(2)
	(*ppTail1)->pNext=*ppHead1;							//CIRCULAR EFFECT
	*ppHead2=*ppTail2=NULL;
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
void ConcatAtPosition(struct Node **ppHead1,struct Node **ppTail1,
					  struct Node **ppHead2,struct Node **ppTail2,int iPos)
{
	int iCount=0;
	struct Node *pTemp=NULL;
	if(iPos<=0||iPos>(iCount=CountNodes(*ppHead1,*ppTail1)+1))
		return;
	if(NULL==*ppHead2)
		return;
	if(1==iPos)
	{
		ConcatList(ppHead2,ppTail2,ppHead1,ppTail1);
		*ppHead1=*ppHead2;
		*ppTail1=*ppTail2;
		*ppHead2=*ppTail2=NULL;
	}
	if(iPos==iCount+1)
	{
		ConcatList(ppHead1,ppTail1,ppHead2,ppTail2);
		return;
	}
	pTemp=*ppHead1;
	iCount=1;
	while(iCount<iPos-1)
	{
		iCount++;
		pTemp=pTemp->pNext;
	}
	(*ppTail2)->pNext=pTemp->pNext;
	pTemp->pNext->pPrev=*ppTail2;							//--------------------------(1)
	pTemp->pNext=*ppHead2;
	(*ppHead2)->pPrev=pTemp;								//--------------------------(2)
	*ppHead2=*ppTail2=NULL;
}
