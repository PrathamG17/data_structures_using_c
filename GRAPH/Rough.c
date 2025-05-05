int LeafNodeCount(struct Node *pHead)
{
	if(NULL==pHead)
		return 0;
		
	if(NULL==pHead->pLeft && NULL==pHead->pRight)
		return 1;
		
	return (LeafNodeCount(pHead->pLeft)+LeafNodeCount(pHead->pRight));
}
int NonLeafNodeCount(struct Node *pHead)
{
	if(NULL==pHead)
		return 0;
		
	if(pHead->pLeft!=NULL || pHead->pRight!=NULL)
		return (NonLeafNodeCount(pHead->pLeft)+NonLeafNodeCount(pHead->pRight)+1);
	
	return 0;
}
void DFS(struct Vertex *pHead)
{
	struct Edge *pTemp2=NULL;
	struct Vertex *pTemp1=NULL;
	struct Vertex *pTemp3=NULL;
	
	Push(&pStack,pHead);
	while((pTemp1=Pop(&pStack)) != NULL)
	{
		InsertVisited(&pVisit,pTemp1);
		
		pTemp2=pTemp1->pAdjEdge;
		while(pTemp2 != NULL)
		{
			pTemp3=pStack;
			while(pTemp3 != NULL)
			{
				if(pTemp2->pAdjVertex == pTemp3->pVertex)
					break;
				pTemp3=pTemp3->pNext;
			}
			
			if(NULL == pTemp3)
			{
				pTemp3=pVisit;
				while(pTemp3 != NULL)
				{
					if(pTemp2->pAdjVertex == pTemp3->pVertex)
						break;
					pTemp3=pTemp3->pNext;
				}
			}
			
			if(pTemp3 != NULL)
			{
				pTemp2=pTemp2->pNextEdge;
				continue;
			}
			
			Push(&pStack,pTemp2->pAdjVertex);
			pTemp2=pTemp2->pNextEdge;
		}
	}
}

void InsertVisit(struct Node **ppHead,struct Vertex *pVertex)
{
	struct Node *pTemp=NULL;
	struct Node *pNewNode=NULL;

	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL == pNewNode)
	{
		printf("MEMORY ALLOCATION FAILED\n");
		return;
	}
	
	pNewNode->pVertex=pVertex;
	pNewNode->pNext=NULL;
	
	if(NULL == *ppHead)
		*ppHead=pNewNode;
	else
	{
		pTemp=*ppHead;
		while(pTemp->pNext != NULL)
			pTemp=pTemp->pNext;
		pTemp->pNext=pNewNode;
	}
}

date-15-11-23
struct Node
{
	int iNo;
	struct Node *pNext;
};

struct Visit
{
	struct Vertex *pVertex;
	struct Visit *pNext;
};
int Pop(struct Node **ppHead);
int IsFull(struct Node *pHead);
int IsEmpty(struct Node *pHead);
void Display(struct Node *pHead);
int CountNodes(struct Node *pHead);
void DeleteAll(struct Node **ppHead);
void Push(struct Node **ppHead,int iData);

void DFS(struct Vertex *pHead);
void InsertVisit(struct Node **ppHead,struct Vertex *pVertex);
	struct Node *pStack=NULL;
	struct Visit *pVisit=NULL;
	
	DFS(&pStack,&pVisit,pFirst);

void DFS(struct Node **ppHead,struct Visit **ppHead,struct Vertex *pHead)		//continue
{
	struct Edge *pTemp2=NULL;
	struct Vertex *pTemp1=NULL;
	struct Vertex *pTemp3=NULL;
	
	Push(&pStack,pHead);
	while((pTemp1=Pop(&pStack)) != NULL)
	{
		InsertVisited(&pVisit,pTemp1);
		
		pTemp2=pTemp1->pAdjEdge;
		while(pTemp2 != NULL)
		{
			pTemp3=pStack;
			while(pTemp3 != NULL)
			{
				if(pTemp2->pAdjVertex == pTemp3->pVertex)
					break;
				pTemp3=pTemp3->pNext;
			}
			
			if(NULL == pTemp3)
			{
				pTemp3=pVisit;
				while(pTemp3 != NULL)
				{
					if(pTemp2->pAdjVertex == pTemp3->pVertex)
						break;
					pTemp3=pTemp3->pNext;
				}
			}
			
			if(pTemp3 != NULL)
			{
				pTemp2=pTemp2->pNextEdge;
				continue;
			}
			
			Push(&pStack,pTemp2->pAdjVertex);
			pTemp2=pTemp2->pNextEdge;
		}
	}
}

void InsertVisit(struct Node **ppHead,struct Vertex *pVertex)
{
	struct Node *pTemp=NULL;
	struct Node *pNewNode=NULL;

	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL == pNewNode)
	{
		printf("MEMORY ALLOCATION FAILED\n");
		return;
	}
	
	pNewNode->pVertex=pVertex;
	pNewNode->pNext=NULL;
	
	if(NULL == *ppHead)
		*ppHead=pNewNode;
	else
	{
		pTemp=*ppHead;
		while(pTemp->pNext != NULL)
			pTemp=pTemp->pNext;
		pTemp->pNext=pNewNode;
	}
}
