#include<stdio.h>
#include<malloc.h>
struct Node
{
	struct Node *pPrev;
	int iNo;
	struct Node *pNext;
};
void Display(struct Node *pHead);
int CountNodes(struct Node *pHead);
void DeleteAll(struct Node **ppHead);
int DeleteLast(struct Node **ppHead);
int DeleteFirst(struct Node **ppHead);
void ReverseDisplay(struct Node *pHead);
void PhysicalReverse(struct Node **ppHead);
void InsertLast(struct Node **ppHead,int iData);
void InsertFirst(struct Node **ppHead,int iData);
int DeleteAtPosition(struct Node **ppHead,int iPos);
int SearchAllOccurrence(struct Node *pHead,int iKey);
int SearchLastOccurrence(struct Node *pHead,int iKey);
int SearchFirstOccurrence(struct Node *pHead,int iKey);
void ConcatList(struct Node **ppHead1,struct Node **ppHead2);
void InsertAtPosition(struct Node **ppHead,int iData,int iPos);
void ConcatAtPosition(struct Node **ppHead1,struct Node **ppHead2,int iPos);
int main(void)
{
	int iData;
	struct Node *pFirst=NULL;
	struct Node *pSecond=NULL;
	
	printf("\n");
	Display(pFirst);
	printf("\n");
	
	InsertFirst(&pFirst,30);
	InsertFirst(&pFirst,20);
	InsertFirst(&pFirst,10);
	
	printf("\n------AFTER INSERT FIRST LINKED LIST 1------\n\n");
	Display(pFirst);
	printf("\n\n");
	
	InsertLast(&pFirst,40);
	InsertLast(&pFirst,50);
	InsertLast(&pFirst,60);
	
	printf("\n------AFTER INSERT LAST LINKED LIST 1------\n\n");
	Display(pFirst);
	printf("\n\n");
	
	InsertAtPosition(&pFirst,20,4);
	
	printf("\n------AFTER INSERT AT POSITION LINKED LIST 1------\n\n");
	Display(pFirst);
	printf("\n\n");
	
	iData=DeleteFirst(&pFirst);
	if(iData!=-1)
		printf("\nDELETED DATA IS %d\n",iData);
	
	iData=DeleteLast(&pFirst);
	if(iData!=-1)
		printf("\nDELETED DATA IS %d\n",iData);
	
	printf("\n\n------AFTER DELETE FIRST AND LAST LINKED LIST 1------\n\n");
	Display(pFirst);
	printf("\n\n");
	
	iData=DeleteAtPosition(&pFirst,4);
	if(iData!=-1)
		printf("\nDELETED DATA IS %d\n\n",iData);
	
	printf("\n------AFTER DELETE AT POSITION LINKED LIST 1------\n\n");
	Display(pFirst);
	printf("\n\n"); 
	
	iData=SearchFirstOccurrence(pFirst,20);
	if(iData!=0)
		printf("\nFIRST OCCURRENCE OF %d FOUND AT %d POSITION\n",20,iData);

	iData=SearchLastOccurrence(pFirst,20);
	if(iData!=0)
		printf("\nLAST OCCURRENCE OF %d FOUND AT %d POSITION\n\n",20,iData);
	
	iData=SearchAllOccurrence(pFirst,20);
	printf("%d FOUND %d TIMES\n\n",20,iData);
	
	iData=CountNodes(pFirst);
	printf("TOTAL NODES =%d\n\n",iData);
	
	printf("\n------LINKED LIST 1------\n\n");
	Display(pFirst);
	printf("\n");
	printf("\n\n------AFTER PHYSICAL REVERSE LINKED LIST 1------\n");
	PhysicalReverse(&pFirst);
	printf("\n");
	Display(pFirst);
	printf("\n");
	
	PhysicalReverse(&pFirst);
	printf("\n\n------LINKED LIST 1------\n\n");
	Display(pFirst);
	printf("\n");
	
	printf("\n\n------REVERSE DISPLAY LINKED LIST 1------\n\n");
	ReverseDisplay(pFirst);
	printf("\n\n");
	
	InsertLast(&pSecond,100);
	InsertLast(&pSecond,200);
	InsertLast(&pSecond,300);
	
	printf("\n------LINKED LIST1------\n\n");
	Display(pFirst);
	printf("\n");
	printf("\n------LINKED LIST2------\n\n");	
	Display(pSecond);
	printf("\n");
	ConcatList(&pFirst,&pSecond);
	printf("\n\n------AFTER CONCAT LIST LINKED LIST 1 LINKED LIST 2------\n");	
	printf("\n------LINKED LIST1------\n\n");
	Display(pFirst);
	printf("\n");
	printf("\n------LINKED LIST2------\n\n");	
	Display(pSecond);
	printf("\n");
	
	InsertLast(&pSecond,1000);
	InsertLast(&pSecond,2000);
	InsertLast(&pSecond,3000);
	
	printf("\n\n------LINKED LIST1------\n\n");
	Display(pFirst);
	printf("\n");
	printf("\n------NEW LINKED LIST2------\n\n");	
	Display(pSecond);
	printf("\n");
	ConcatAtPosition(&pFirst,&pSecond,3);
	printf("\n\n------AFTER CONCAT AT POSITION------\n");
	printf("\n------LINKED LIST1------\n\n");
	Display(pFirst);
	printf("\n");
	printf("\n------LINKED LIST2------\n\n");	
	Display(pSecond);
	printf("\n");
	
	if(pFirst!=NULL)
	{
		DeleteAll(&pFirst);
		pFirst=NULL;
	}
	
	if(pSecond!=NULL)
	{
		DeleteAll(&pSecond);
		pSecond=NULL;
	}
	
	printf("\n\n------AFTER DELETE ALL------\n");
	printf("\n------LINKED LIST1------\n\n");
	Display(pFirst);
	printf("\n");
	printf("\n------LINKED LIST2------\n\n");	
	Display(pSecond);
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
		printf("\nMEMORY ALLOCATION FAILED\n\n");
		return;
	}
	pNewNode->iNo=iData;
	pNewNode->pNext=NULL;
	if(*ppHead!=NULL)
	{
		pTemp=*ppHead;
		while(pTemp->pNext!=NULL)
			pTemp=pTemp->pNext;
		pNewNode->pPrev=pTemp;		
		pTemp->pNext=pNewNode;
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
int DeleteFirst(struct Node **ppHead)
{
	int iDelData;
	if(NULL==*ppHead)
		return -1;
	iDelData=(*ppHead)->iNo;
	if((*ppHead)->pNext!=NULL)
	{
		*ppHead=(*ppHead)->pNext;
		(*ppHead)->pPrev->pNext=NULL;
		free((*ppHead)->pPrev);
		(*ppHead)->pPrev=NULL;
	}
	else
	{
		free(*ppHead);
		*ppHead=NULL;
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
	
	if(pTemp->pPrev!=NULL)
	{
		pTemp->pPrev->pNext=NULL;
		pTemp->pPrev=NULL;
	}
	else
		*ppHead=NULL;
	
	free(pTemp);
	pTemp=NULL;
	
	return iDelData;
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
	if(pTemp->pNext!=NULL)				//------------------------------ONYL IF NOT LAST NODE 
		pTemp->pNext->pPrev=pTemp->pPrev;
	pTemp->pPrev=pTemp->pNext=NULL;
	free(pTemp);
	pTemp=NULL;
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
	int iCount;
	struct Node *pTemp1=NULL;
	struct Node *pTemp2=NULL;
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
		ConcatList(ppHead2,ppHead1);
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
