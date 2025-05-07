#include<stdio.h>
#include<malloc.h>
struct Node
{
	struct Node *pPrev;
	int iNo;
	struct Node *pNext;
};
void InsertAtPosition(struct Node **,int,int);
void InsertFirst(struct Node **,int);
void InsertLast(struct Node **,int);
int CountNodes(struct Node *);
void Display(struct Node *);
void DeleteAll(struct Node **);
int main(void)
{
	struct Node *pFirst=NULL;
	
	InsertAtPosition(&pFirst,10,1);
	printf("\nDATA %d IS INSERTED IN NODE %d\n",10,1);
	
	InsertAtPosition(&pFirst,20,2);
	printf("\nDATA %d IS INSERTED IN NODE %d\n",20,2);
	
	printf("\n------AFTER INSERTION------\n\n");
	Display(pFirst);
	printf("\n");
	
	InsertAtPosition(&pFirst,50,3);
	printf("\nDATA %d IS INSERTED IN NODE %d\n",50,3);
	
	printf("\n------AFTER INSERTION------\n\n");
	Display(pFirst);
	printf("\n");
	
	InsertAtPosition(&pFirst,30,3);
	printf("\nDATA %d IS INSERTED IN NODE %d\n",30,3);
	
	printf("\n------AFTER INSERTION------\n\n");
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
	//if(pNewNode->pNext!=NULL)
	pNewNode->pNext->pPrev=pNewNode;
	pTemp->pNext=pNewNode;
	pNewNode->pPrev=pTemp;
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
		pNewNode->pNext->pPrev=pNewNode;
	*ppHead=pNewNode;
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
