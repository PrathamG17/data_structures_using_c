#include<stdio.h>
#include<malloc.h>
struct Node
{
	int iNo;
	struct Node *pNext;
};
void InsertFirst(struct Node **,int);
void Display(struct Node *);
int SearchFirstOccurrence(struct Node *,int);
void DeleteAll(struct Node **);
int main(void)
{
	int iPos;
	struct Node *pFirst=NULL;
	
	printf("\n");
	Display(pFirst);
	printf("\n");
	
	InsertFirst(&pFirst,10);
	InsertFirst(&pFirst,20);
	InsertFirst(&pFirst,30);
	InsertFirst(&pFirst,40);
	InsertFirst(&pFirst,50);
	
	printf("\n------AFTER INSERTION------\n\n");
	Display(pFirst);
	printf("\n");
	
	iPos=SearchFirstOccurrence(pFirst,30);
	if(iPos!=0)
		printf("\n\nDATA %d FOUND FIRST IN NODE %d.\n",30,iPos);
	else
		printf("\n\nDATA %d NOT FOUND.\n",30);
	
	iPos=SearchFirstOccurrence(pFirst,70);
	if(iPos!=0)
		printf("\n\nDATA %d FOUND FIRST IN NODE %d.\n",70,iPos);
	else
		printf("\n\nDATA %d NOT FOUND.\n",70);
	
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
		printf("\nMEMORY ALLOCATION FAILED\n");
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
		printf("LIST IS EMPTY");
		return;
	}
	while(pHead!=NULL)
	{
		printf("|%d|->",pHead->iNo);
		pHead=pHead->pNext;
	}
}
int SearchFirstOccurrence(struct Node *pHead,int iData)
{
	int iCount;
	while(pHead!=NULL)
	{
		iCount++;
		if(iData==pHead->iNo)
			return iCount;
		pHead=pHead->pNext;
	}
	return 0;
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
