#define MAX 5
struct Node
{
	int iNo;
	struct Node *pNext;
};
int Pop(struct Node **ppHead);
int IsFull(struct Node *pHead);
int IsEmpty(struct Node *pHead);
void Display(struct Node *pHead);
int CountNodes(struct Node *pHead);
void DeleteAll(struct Node **ppHead);
void Push(struct Node **ppHead,int iData);
void Push(struct Node **ppHead,int iData)
{
	struct Node *pNewNode=NULL;
	if(IsFull(*ppHead))
	{
		printf("\nSTACK IS OVERFLOW\n\n");
		return;
	}
	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("\nMEMORY ALLOCATION FAILED\n\n");
		return;
	}
	pNewNode->iNo=iData;
	pNewNode->pNext=*ppHead;
	*ppHead=pNewNode;
}
int Pop(struct Node **ppHead)
{
	int iDelData;
	struct Node *pTemp=NULL;
	if(IsEmpty(*ppHead))
	{
		printf("\nSTACK IS EMPTY\n\n");
		return -1; 
	}
	pTemp=*ppHead;
	*ppHead=pTemp->pNext;
	iDelData=pTemp->iNo;
	pTemp->pNext=NULL;
	free(pTemp);
	pTemp=NULL;
	return iDelData;
}
int IsFull(struct Node *pHead)
{
	int iCount;
	iCount=CountNodes(pHead);
	if(iCount==MAX)
		return 1;
	return 0;
}
int IsEmpty(struct Node *pHead)
{
	if(NULL==pHead)
		return 1;
	return 0;
}
void Display(struct Node *pHead)
{
	if(NULL==pHead)
	{
		printf("\nSTCAK IS EMPTY\n");
		return;
	}
	while(pHead!=NULL)
	{
		printf("\t%d\n",pHead->iNo);
		pHead=pHead->pNext;
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
