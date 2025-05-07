#include<stdio.h>
#include<malloc.h>
struct Node
{
	struct Node *pPrev;
	int iNo;
	struct Node *pNext;
};
void InsertLast(struct Node **,int);
void Display(struct Node *);
int SearchLastOccurrence(struct Node *,int);
void DeleteAll(struct Node **);
int main(void)
{
	int iPos;
	struct Node *pFirst=NULL;
	
	printf("\n");
	Display(pFirst);
	printf("\n");
	
	InsertLast(&pFirst,10);
	InsertLast(&pFirst,40);
	InsertLast(&pFirst,30);
	InsertLast(&pFirst,10);
	InsertLast(&pFirst,40);
	
	printf("\n------AFTER INSERTION------\n\n");
	Display(pFirst);
	printf("\n");
	
	iPos=SearchLastOccurrence(pFirst,10);
	if(iPos!=0)
		printf("\nDATA %d FOUND LAST IN NODE %d.\n",10,iPos);
	else
		printf("\nDATA %d NOT FOUND.\n",10);

	iPos=SearchLastOccurrence(pFirst,70);
	if(iPos!=0)
		printf("\nDATA %d FOUND LAST IN NODE %d.\n",70,iPos);
	else
		printf("\nDATA %d NOT FOUND.\n",70);
	
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
void InsertLast(struct Node **ppHead,int iData)
{
	struct Node *pNewNode=NULL,*pTemp=NULL;
	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("\nMEMORY ALLOCATION FAILED\n");
		return;
	}
	pNewNode->iNo=iData;
	pNewNode->pNext=NULL;
	if(NULL==*ppHead)
	{
		pNewNode->pNext=NULL;
		*ppHead=pNewNode;
	}
	else
	{
		pTemp=*ppHead;
		while(pTemp->pNext!=NULL)
			pTemp=pTemp->pNext;
		pTemp->pNext=pNewNode;
		pNewNode->pPrev=pTemp;
	}
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
