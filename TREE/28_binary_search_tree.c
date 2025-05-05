#include<stdio.h>
#include<malloc.h>
#define MAX 15

struct Node
{
	struct Node *pLeft;
	int iNo;
	struct Node *pRight;
};
struct Queue
{
	struct Node *pNode;
	struct Queue *pNext;
};

int Height(struct Node *pHead);
void InOrder(struct Node *pHead);
void PreOrder(struct Node *pHead);
void PostOrder(struct Node *pHead);
int CountNodes(struct Node *pHead);
int LargestBST(struct Node *pHead);
int SmallestBST(struct Node *pHead);
void LevelOrder(struct Node *pHead);
void DeleteAll(struct Node **ppHead);
int LeafNodeCount(struct Node *pHead);
int NonLeafNodeCount(struct Node *pHead);
void InsertBST(struct Node **ppHead,int iData);
void DeleteNode(struct Node **ppHead,int iData);
struct Node * SearchRecursive(struct Node *pHead,int iKey);
struct Node * SearchNonRecursive(struct Node *pHead,int iKey);

int IsQueueFull(struct Queue *pHead);
int IsQueueEmpty(struct Queue *pHead);
int CountNodesQueue(struct Queue *pHead);
struct Node * DeQueue(struct Queue **ppHead);
void EnQueue(struct Queue **ppHead,struct Node *pHead);

int main(void)
{
	int iTemp;
	struct Node *pTemp=NULL;
	struct Node *pRoot=NULL;
	
	InsertBST(&pRoot,35);
	InsertBST(&pRoot,33);
	InsertBST(&pRoot,42);
	InsertBST(&pRoot,25);
	InsertBST(&pRoot,40);
	InsertBST(&pRoot,60);
	InsertBST(&pRoot,30);
	InsertBST(&pRoot,58);
	InsertBST(&pRoot,50);
	InsertBST(&pRoot,48);

	printf("\n\n#IN-ORDER DISPLAY:\n");
	InOrder(pRoot);

	printf("\n\n#PRE-ORDER DISPLAY:\n");
	PreOrder(pRoot);
	
	printf("\n\n#POST-ORDER DISPLAY:\n");
	PostOrder(pRoot);

	printf("\n\n#LEVEL-ORDER DISPLAY:\n");
	LevelOrder(pRoot);

	printf("TOTAL NODES=%d\n\n",CountNodes(pRoot));
	printf("TOTAL LEAF NODES=%d\n\n",LeafNodeCount(pRoot));
	printf("TOTAL NON-LEAF NODES=%d\n\n",NonLeafNodeCount(pRoot));
	printf("TOTAL HEIGHT OF TREE=%d\n",Height(pRoot));

	pTemp=SearchRecursive(pRoot,58);
	if(pTemp!=NULL)
		printf("\nDATA %d FOUND.\n\n",pTemp->iNo);
	else
		printf("DATA %d NOT FOUND.\n\n",58);
	
	pTemp=SearchNonRecursive(pRoot,29);
	if(pTemp!=NULL)
		printf("\nDATA %d FOUND.\n\n",pTemp->iNo);
	else
		printf("DATA %d NOT FOUND.\n\n",29);
	
	iTemp=SmallestBST(pRoot);
	if(-1 != iTemp)
		printf("SMALLEST DATA IS %d.\n\n",iTemp);

	iTemp=LargestBST(pRoot);
	if(-1 != iTemp)
		printf("LARGEST DATA IS %d.",iTemp);
	
	DeleteNode(&pRoot,30);
	printf("\n\n#PRE-ORDER DISPLAY:\n");
	PreOrder(pRoot);
	
	DeleteNode(&pRoot,33);
	printf("\n\n#PRE-ORDER DISPLAY:\n");
	PreOrder(pRoot);

	DeleteNode(&pRoot,42);
	printf("\n\n#PRE-ORDER DISPLAY:\n");
	PreOrder(pRoot);
	
	if(pRoot!=NULL)
	{
		DeleteAll(&pRoot);
		pRoot=NULL;
	}
	
	return 0;
}
void InsertBST(struct Node **ppHead,int iData)
{
	struct Node *pNewNode=NULL;
	struct Node *pTemp=NULL;
	struct Node *pParent=NULL;

	pTemp=*ppHead;
	while(pTemp!=NULL)
	{
		pParent=pTemp;
		
		if(iData < pTemp->iNo)
			pTemp=pTemp->pLeft;
		else if(iData > pTemp->iNo)
			pTemp=pTemp->pRight;
		else
		{
			printf("DUPLICATE DATA\n\n");
			return;
		}
	}

	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("MEMORY ALLOCATION FAILED\n\n");
		return;
	}
	
	pNewNode->iNo=iData;
	pNewNode->pLeft=pNewNode->pRight=NULL;
	
	if(NULL==*ppHead)											
		*ppHead=pNewNode;
	else if(iData < pParent->iNo)
		pParent->pLeft=pNewNode;
	else
		pParent->pRight=pNewNode;
}
void InOrder(struct Node *pHead)
{
	if(NULL==pHead)
		return;
	
	InOrder(pHead->pLeft);
	printf("%d\t",pHead->iNo);
	InOrder(pHead->pRight);
}
void PreOrder(struct Node *pHead)
{
	if(NULL==pHead)
		return;
	
	printf("%d\t",pHead->iNo);
	PreOrder(pHead->pLeft);
	PreOrder(pHead->pRight);
}
void PostOrder(struct Node *pHead)
{
	if(NULL==pHead)
		return;
	
	PostOrder(pHead->pLeft);
	PostOrder(pHead->pRight);
	printf("%d\t",pHead->iNo);
}
void LevelOrder(struct Node *pHead)
{
	struct Queue *pQueue=NULL;
	struct Node *pTemp=NULL;

	EnQueue(&pQueue,pHead);
	while((pTemp=DeQueue(&pQueue))!=NULL)
	{
		printf("%d\t",pTemp->iNo);
		if(pTemp->pLeft!=NULL)
			EnQueue(&pQueue,pTemp->pLeft);
		if(pTemp->pRight!=NULL)
			EnQueue(&pQueue,pTemp->pRight);
	}
	printf("\n\n");
}
int CountNodes(struct Node *pHead)
{
	static int iCount=0;
	
	if(NULL==pHead)
		return 0;
	
	iCount++;
	CountNodes(pHead->pLeft);
	CountNodes(pHead->pRight);
	
	return iCount;
}
int Height(struct Node *pHead)
{
	int iLeftHeight;
	int iRightHeight;
	
	if(NULL==pHead)
		return 0;

	iLeftHeight=Height(pHead->pLeft);
	iRightHeight=Height(pHead->pRight);

	if(iLeftHeight>iRightHeight)
		return (iLeftHeight+1);
	else
		return (iRightHeight+1);
}
int LeafNodeCount(struct Node *pHead)
{
	static int iCount=0;
	
	if(NULL==pHead)
		return 0;
	
	if(NULL==pHead->pLeft && NULL==pHead->pRight)
		iCount++;
	
	LeafNodeCount(pHead->pLeft);
	LeafNodeCount(pHead->pRight);
	
	return iCount;
}
int NonLeafNodeCount(struct Node *pHead)
{
	static int iCount=0;
	
	if(NULL==pHead)
		return 0;
	
	if(pHead->pLeft!=NULL || pHead->pRight!=NULL)
		iCount++;
	
	NonLeafNodeCount(pHead->pLeft);
	NonLeafNodeCount(pHead->pRight);
	
	return iCount;
}
struct Node * SearchNonRecursive(struct Node *pHead,int iKey)
{
	while(pHead!=NULL)
	{
		if(iKey<pHead->iNo)
			pHead=pHead->pLeft;
		else if(iKey>pHead->iNo)
			pHead=pHead->pRight;
		else												
			break;
	}
	return pHead;
}
struct Node * SearchRecursive(struct Node *pHead,int iKey)
{
	while(pHead!=NULL)
	{
		if(iKey<pHead->iNo)
			return SearchRecursive(pHead->pLeft,iKey);
		else if(iKey>pHead->iNo)
			return SearchRecursive(pHead->pRight,iKey);
		else 												
			break;
	}
	return pHead;
}
void DeleteNode(struct Node **ppHead,int iData)
{
	struct Node *pChild=NULL;
	struct Node *pParent=NULL;
	struct Node *pTemp=*ppHead;
	struct Node *pSuccessor=NULL;
	
	if(NULL==*ppHead)										
		return;
	
	while(pTemp != NULL)								
	{
		if(iData == pTemp->iNo)
			break;
		
		pParent=pTemp;
		if(iData < pTemp->iNo)
			pTemp=pTemp->pLeft;
		else if(iData > pTemp->iNo)
			pTemp=pTemp->pRight;
	}
	
	if(pTemp->pLeft != NULL && pTemp->pRight != NULL)		
	{
		pParent=pTemp;										
		pSuccessor=pTemp->pRight;							
		
		while(pSuccessor->pLeft != NULL)					
		{
			pParent=pSuccessor;								
			pSuccessor=pSuccessor->pLeft;
		}
		
		pTemp->iNo=pSuccessor->iNo;							
		pTemp=pSuccessor;									
	}
	
	if(pTemp->pLeft != NULL)								
		pChild=pTemp->pLeft;
	else
		pChild=pTemp->pRight;								
	
	if(NULL == pParent)										
		*ppHead=pChild;
	else if(pParent->pLeft == pTemp)						
		pParent->pLeft=pChild;
	else
		pParent->pRight=pChild;
	
	free(pTemp);
	
	pTemp=NULL;
	pChild=NULL;
	pSuccessor=NULL;
}
void DeleteAll(struct Node **ppHead)
{
	if(NULL==*ppHead)
		return;
	
	DeleteAll(&((*ppHead)->pLeft));					
	DeleteAll(&((*ppHead)->pRight));				
	
	free(*ppHead);
	*ppHead=NULL;
}
int SmallestBST(struct Node *pHead)
{
	if(NULL == pHead)
		return -1;
		
	while(pHead->pLeft != NULL)
		pHead=pHead->pLeft;
		
	return (pHead->iNo);
}
int LargestBST(struct Node *pHead)
{
	if(NULL == pHead)
		return -1;
		
	while(pHead->pRight != NULL)
		pHead=pHead->pRight;
		
	return (pHead->iNo);
}

void EnQueue(struct Queue **ppHead,struct Node *pHead)
{
	struct Queue *pNewNode=NULL;
	struct Queue *pTemp=NULL;
	
	if(IsQueueFull(*ppHead))
		return;
	pNewNode=(struct Queue *)malloc(sizeof(struct Queue));
	if(NULL==pNewNode)
	{
		printf("MEMORY ALLOCATION FAILED\n\n");
		return;
	}
	pNewNode->pNode=pHead;
	pNewNode->pNext=NULL;
	if(*ppHead!=NULL)
	{
		pTemp=*ppHead;
		while(pTemp->pNext!=NULL)
			pTemp=pTemp->pNext;
		pTemp->pNext=pNewNode;
	}
	else
		*ppHead=pNewNode;
}
struct Node * DeQueue(struct Queue **ppHead)
{
	struct Queue *pTemp1=NULL;
	struct Node *pTemp2=NULL;
	if(IsQueueEmpty(*ppHead))
		return NULL;
	pTemp1=*ppHead;
	*ppHead=pTemp1->pNext;
	pTemp2=pTemp1->pNode;
	pTemp1->pNext=NULL;
	free(pTemp1);
	pTemp1=NULL;
	return pTemp2;
}
int IsQueueFull(struct Queue *pHead)
{
	if(MAX==CountNodesQueue(pHead))
		return 1;
	return 0;
}
int IsQueueEmpty(struct Queue *pHead)
{
	if(NULL==pHead)
		return 1;
	return 0;
}
int CountNodesQueue(struct Queue *pHead)
{
	int iCount=0;
	while(pHead!=NULL)
	{
		iCount++;
		pHead=pHead->pNext;
	}
	return iCount;
}
