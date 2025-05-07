#include<stdio.h>
#include<malloc.h>
struct Node
{
	int iNo;
	struct Node *pNext;
};
void Display(struct Node *pHead,struct Node *pTail);
int CountNodes(struct Node *pHead,struct Node *pTail);
void DeleteAll(struct Node **ppHead,struct Node **ppTail);
int DeleteLast(struct Node **ppHead,struct Node **ppTail);
int DeleteFirst(struct Node **ppHead,struct Node **ppTail);
void ConcatList(struct Node **ppHead1,struct Node **ppTail1,
				struct Node **ppHead2,struct Node **ppTail2);
void ReverseDisplay(struct Node *ppHead,struct Node *ppTail);
void PhysicalReverse(struct Node **ppHead,struct Node **ppTail);
void InsertLast(struct Node **ppHead,struct Node **ppTail,int iData);
void InsertFirst(struct Node **ppHead,struct Node **ppTail,int iData);
int SearchAllOccurrence(struct Node *pHead,struct Node *pTail,int iKey);
int SearchLastOccurrence(struct Node *pHead,struct Node *pTail,int iKey);
int DeleteAtPosition(struct Node **ppHead,struct Node **ppTail,int iPos);
int SearchFirstOccurrence(struct Node *pHead,struct Node *pTail,int iKey);
void ConcatAtPosition(struct Node **ppHead1,struct Node **ppTail1,
					  struct Node **ppHead2,struct Node **ppTail2,int iPos);
void InsertAtPosition(struct Node **ppHead,struct Node **ppTail,int iPos,int iData);
int main(void)
{
	int iData;
	struct Node *pFirst1=NULL;
	struct Node *pLast1=NULL;
	struct Node *pFirst2=NULL;
	struct Node *pLast2=NULL;
	
	Display(pFirst1,pLast1);
	
	InsertFirst(&pFirst1,&pLast1,30);
	InsertFirst(&pFirst1,&pLast1,20);
	InsertFirst(&pFirst1,&pLast1,10);
	
	Display(pFirst1,pLast1);
	
	InsertLast(&pFirst1,&pLast1,40);
	InsertLast(&pFirst1,&pLast1,50);
	InsertLast(&pFirst1,&pLast1,60);
	
	Display(pFirst1,pLast1);
	
	InsertAtPosition(&pFirst1,&pLast1,4,20);
	
	Display(pFirst1,pLast1);
	
	iData=DeleteFirst(&pFirst1,&pLast1);
	if(iData!=-1)
		printf("DELETED DATA IS %d\n\n",iData);
	
	iData=DeleteLast(&pFirst1,&pLast1);
	if(iData!=-1)
		printf("DELETED DATA IS %d\n\n",iData);
	
	Display(pFirst1,pLast1);
	
	iData=DeleteAtPosition(&pFirst1,&pLast1,4);
	if(iData!=-1)
		printf("DELETED DATA IS %d\n\n",iData);
	
	Display(pFirst1,pLast1);
	
	iData=SearchFirstOccurrence(pFirst1,pLast1,20);
	if(iData!=0)
		printf("DATA %d FOUND FIRST IN NODE %d\n\n",20,iData);

	iData=SearchLastOccurrence(pFirst1,pLast1,20);
	if(iData!=0)
		printf("DATA %d FOUND LAST IN NODE %d\n\n",20,iData);
	
	iData=SearchAllOccurrence(pFirst1,pLast1,20);
	printf("%d FOUND %d TIMES\n\n",20,iData);
	
	iData=CountNodes(pFirst1,pLast1);
	printf("TOTAL NODES =%d\n\n",iData);
	
	Display(pFirst1,pLast1);

	PhysicalReverse(&pFirst1,&pLast1);

	Display(pFirst1,pLast1);
	
	PhysicalReverse(&pFirst1,&pLast1);

	Display(pFirst1,pLast1);
	
	ReverseDisplay(pFirst1,pLast1);
	
	InsertLast(&pFirst2,&pLast2,100);
	InsertLast(&pFirst2,&pLast2,200);
	InsertLast(&pFirst2,&pLast2,300);
	
	Display(pFirst2,pLast2);

	ConcatList(&pFirst1,&pLast1,&pFirst2,&pLast2);

	Display(pFirst1,pLast1);

	Display(pFirst2,pLast2);
	
	InsertLast(&pFirst2,&pLast2,1000);
	InsertLast(&pFirst2,&pLast2,2000);
	InsertLast(&pFirst2,&pLast2,3000);
	
	Display(pFirst1,pLast1);

	Display(pFirst2,pLast2);

	ConcatAtPosition(&pFirst1,&pLast1,&pFirst2,&pLast2,3);

	Display(pFirst1,pLast1);

	Display(pFirst2,pLast2);
	
	if(pFirst1!=NULL)
	{
		DeleteAll(&pFirst1,&pLast1);
		pFirst1=pLast1=NULL;
	}
	
	if(pFirst2!=NULL)
	{
		DeleteAll(&pFirst2,&pLast2);
		pFirst2=pLast2=NULL;
	}
	
	Display(pFirst1,pLast1);

	Display(pFirst2,pLast2);
	
	return 0;
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
	if(*ppHead!=NULL)
	{	pNewNode->pNext=*ppHead;
		*ppHead=pNewNode;
	}
	else
		*ppHead=*ppTail=pNewNode;
	(*ppTail)->pNext=*ppHead;							//CIRCULAR EFFECT
}
void InsertLast(struct Node **ppHead,struct Node **ppTail,int iData)
{
	struct Node *pNewNode=NULL;
	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("MEMORY ALLOCATION FAILED\n\n");
		return;
	}
	pNewNode->iNo=iData;
	if(*ppHead!=NULL)
	{
		(*ppTail)->pNext=pNewNode;
		*ppTail=pNewNode;
	}
	else
		*ppHead=*ppTail=pNewNode;
	(*ppTail)->pNext=*ppHead;						//CIRCULAR EFFECT
}
void InsertAtPosition(struct Node **ppHead,struct Node **ppTail,int iPos,int iData)
{
	int iCount;
	struct Node *pNewNode=NULL;
	struct Node *pTemp=NULL;
	if(iPos<=0||iPos>(iCount=CountNodes(*ppHead,*ppTail)+1))
	{
		printf("INVALID POSITION\n\n");
		return;
	}
	if(1==iPos)
	{
		InsertFirst(ppHead,ppTail,iData);
		return;
	}
	if(iPos==iCount+1)
	{
		InsertLast(ppHead,ppTail,iData);
		return;
	}
	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("MEMORY ALLOCATION FAILED\n\n");
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
int DeleteFirst(struct Node **ppHead,struct Node **ppTail)
{
	int iDelData;
	if(NULL==*ppHead)
	{
		printf("LINKED LIST EMPTY\n\n");
		return -1;
	}
	iDelData=(*ppHead)->iNo;
	if(*ppHead!=*ppTail)			//----------------------------
	{
		*ppHead=(*ppHead)->pNext;
		(*ppTail)->pNext->pNext=NULL;
		free((*ppTail)->pNext);
		(*ppTail)->pNext=*ppHead;						//CIRCULAR EFFECT							
	}
	else
	{
		(*ppHead)->pNext=NULL;
		free(*ppHead);
		*ppHead=*ppTail=NULL;
	}
	return iDelData;
}
int DeleteLast(struct Node **ppHead,struct Node **ppTail)
{
	int iDelData;
	struct Node *pTemp=NULL;
	if(NULL==*ppHead)
	{
		printf("LINKED LIST IS EMPTY\n\n");
		return -1;
	}
	iDelData=(*ppTail)->iNo;
	if(*ppHead!=*ppTail)
	{
		pTemp=*ppHead;
		while(pTemp->pNext!=*ppTail)
			pTemp=pTemp->pNext;
		*ppTail=pTemp;
		(*ppTail)->pNext->pNext=NULL;
		free((*ppTail)->pNext);
		(*ppTail)->pNext=*ppHead;						//CIRCULAR EFFECT
	}
	else
	{
		(*ppTail)->pNext=NULL;
		free(*ppTail);
		*ppHead=*ppTail=NULL;
	}
	return iDelData;
}
int DeleteAtPosition(struct Node **ppHead,struct Node **ppTail,int iPos)
{
	int iCount=0;
	struct Node *pTemp1=NULL;
	struct Node *pTemp2=NULL;
	if(iPos<=0||iPos>(iCount=CountNodes(*ppHead,*ppTail)))
	{
		printf("INVALID POSITION\n\n");
		return -1;
	}
	if(1==iPos)
		return DeleteFirst(ppHead,ppTail);
	if(iPos==iCount)
		return DeleteLast(ppHead,ppTail);
	pTemp1=*ppHead;
	iCount=1;
	while(iCount<iPos-1)
	{
		iCount++;
		pTemp1=pTemp1->pNext;
	}
	pTemp2=pTemp1->pNext;
	iCount=pTemp2->iNo;
	pTemp1->pNext=pTemp2->pNext;
	pTemp2->pNext=NULL;
	free(pTemp2);
	pTemp2=NULL;
	return iCount;
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
int SearchFirstOccurrence(struct Node *pHead,struct Node *pTail,int iKey)
{
	int iCount=0;
	do
	{
		iCount++;
		if(pHead->iNo==iKey)
			return iCount;
		pHead=pHead->pNext;
	}while(pHead!=(pTail)->pNext);
	return 0;
}
int SearchLastOccurrence(struct Node *pHead,struct Node *pTail,int iKey)
{
	int iCount=0;
	int iLastPos=0;
	do
	{
		iCount++;
		if(pHead->iNo==iKey)
			iLastPos=iCount;
		pHead=pHead->pNext;
	}while(pHead!=(pTail)->pNext);
	return iLastPos;
}
int SearchAllOccurrence(struct Node *pHead,struct Node *pTail,int iKey)
{
	int iCount=0;
	do
	{
		if(pHead->iNo==iKey)
			iCount++;
		pHead=pHead->pNext;
	}while(pHead!=(pTail)->pNext);
	return iCount;
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
	*ppTail1=*ppTail2;
	(*ppTail1)->pNext=*ppHead1;							//CIRCULAR EFFECT
	*ppHead2=*ppTail2=NULL;
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
	pTemp->pNext=*ppHead2;
	*ppHead2=*ppTail2=NULL;
}
void PhysicalReverse(struct Node **ppHead,struct Node **ppTail)
{
	struct Node *pPrev=*ppTail;
	struct Node *pCurrent=*ppHead;
	struct Node *pNext=NULL;
	if(NULL==*ppHead)
		return;
	do
	{
		pNext=pCurrent->pNext;
		pCurrent->pNext=pPrev;
		pPrev=pCurrent;
		pCurrent=pNext;
	}while(pNext!=*ppHead);
	*ppHead=pPrev;
	*ppTail=pNext;
}
void ReverseDisplay(struct Node *ppHead,struct Node *ppTail)
{
	PhysicalReverse(&ppHead,&ppTail);
	Display(ppHead,ppTail);
	PhysicalReverse(&ppHead,&ppTail);

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
