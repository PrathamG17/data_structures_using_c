#include<stdio.h>
#include<malloc.h>
struct Node
{
	int iNo;
	struct Node *pNext;
};
void InsertLast(struct Node **,int);
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
	
	InsertLast(&pFirst,10);
	InsertLast(&pFirst,10);
	InsertLast(&pFirst,40);
	InsertLast(&pFirst,10);
	InsertLast(&pFirst,40);
	
	printf("\n------AFTER INSERTION------\n\n");
	Display(pFirst);
	printf("\n");
	
	iCount=SearchAllOccurrence(pFirst,40);
	if(iCount!=0)
		printf("\nDATA %d FOUND %d TIMES IN THE LINKED LIST.\n\n",40,iCount);
	else
		printf("\nDATA %d NOT FOUND.\n\n",40);
	
	iCount=SearchAllOccurrence(pFirst,70);
	if(iCount!=0)
		printf("\nDATA %d FOUND %d TIMES IN THE LINKED LIST.\n\n",70,iCount);
	else
		printf("\nDATA %d NOT FOUND.\n\n",70);
	
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
		*ppHead=pNewNode;
	else
	{
		pTemp=*ppHead;
		while(pTemp->pNext!=NULL)
			pTemp=pTemp->pNext;
		pTemp->pNext=pNewNode;
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
int SearchAllOccurrence(struct Node *pHead,int iKey)
{
	int iCount1=0;
	while(pHead!=NULL)
	{
		if(iKey==pHead->iNo)
			iCount1++;
		pHead=pHead->pNext;
	}
	return iCount1;
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
