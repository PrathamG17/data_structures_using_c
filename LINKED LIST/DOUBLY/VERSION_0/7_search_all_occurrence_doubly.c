#include<stdio.h>
#include<malloc.h>
struct Node
{
	struct Node *pPrev;
	int iNo;
	struct Node *pNext;
};
void InsertFirst(struct Node **,int);
void Display(struct Node *);
int SearchAllOccurrence(struct Node *,int);
void DeleteAll(struct Node **);
int main(void)
{
	int iCount;
	struct Node *pFirst=NULL;
	
	printf("\n");
	Display(pFirst);
	printf("\n");
	
	InsertFirst(&pFirst,10);
	InsertFirst(&pFirst,40);
	InsertFirst(&pFirst,10);
	InsertFirst(&pFirst,10);
	InsertFirst(&pFirst,40);
	
	printf("\n------AFTER INSERTION------\n\n");
	Display(pFirst);
	printf("\n");
	
	iCount=SearchAllOccurrence(pFirst,10);
	if(iCount!=0)
		printf("\nDATA %d FOUND %d TIMES IN LIST.\n",10,iCount);
	else
		printf("\nDATA %d NOT FOUND.\n",10);
	
	iCount=SearchAllOccurrence(pFirst,70);
	if(iCount!=0)
		printf("\nDATA %d FOUND %d TIMES IN LIST.\n",70,iCount);
	else
		printf("\nDATA %d NOT FOUND.\n",70);
	
	if(pFirst!=NULL)
	{
		DeleteAll(&pFirst);
		pFirst=NULL;
	}
	
	printf("\n------AFTER DELETE ALL------\n");
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
	pNewNode->pPrev=NULL;
	pNewNode->pNext=*ppHead;
	if(*ppHead!=NULL)
		(*ppHead)->pPrev=pNewNode;
	*ppHead=pNewNode;
}
void Display(struct Node *pHead)
{
	if(NULL==pHead)
	{
		printf("\nLIST IS EMPTY");
		return;
	}
	while(pHead!=NULL)
	{
		printf("|%d|->",pHead->iNo);
		pHead=pHead->pNext;
	}
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
