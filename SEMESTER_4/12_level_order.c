#include <stdio.h>
#include <malloc.h>

struct node1;
struct node2;

int Level(struct node1 *,int);
void InsertBST(struct node1 **,int);
int NodesAtLevel(struct  node1 *,int);

int IsEmpty(struct node2 *);
void InitQueue(struct node2 *);
struct node1 * DeQueue(struct node2 *);
void EnQueue(struct node2 *,struct node1 *);

struct node1
{
	int iData;
	struct node1 *pLeft;
	struct node1 *pRight;
};

struct node2
{
	struct node1 * Nodes[10];
	int iRear;
	int iFront;
};

int main(void)
{
	int iVertices;
	int iTemp;
	int iCounter;
	struct node1 *pRoot = NULL;
	
	printf("\nEnter Total Number Of Vertices:-\t");
	scanf("%d",&iVertices);
	
	for(iCounter = 0; iCounter < iVertices; iCounter++)
	{
		printf("\nEnter Vertex %d:-\t",iCounter+1);
		scanf("%d",&iTemp);
		InsertBST(&pRoot,iTemp);
	}
	
	iTemp = Level(pRoot,iVertices);
	
	for(iCounter = 0; iCounter < iTemp; iCounter++)
		printf("\nTotal Nodes At Level %d:-\t%d",iCounter,NodesAtLevel(pRoot,iCounter));
		
	return 0;
}

void InsertBST(struct node1 **ppRoot,int iData)
{
	struct node1 *pNewNode = NULL;
	struct node1 *pTemp = NULL;
	
	pNewNode = (struct node1 *)malloc(sizeof(struct node1));
	if(NULL == pNewNode)
	{
		printf("\nMemory Allocation Failed\n");
		return;
	}
	
	pNewNode->iData = iData;
	pNewNode->pLeft = pNewNode->pRight = NULL;
	
	if(NULL == *ppRoot)
		*ppRoot = pNewNode;
	else
	{
		pTemp = *ppRoot;
		while(pTemp != NULL)
		{
			if(pNewNode->iData > pTemp->iData)
			{
				if(NULL == pTemp->pRight)
				{
					pTemp->pRight = pNewNode;
					break;
				}
				else
					pTemp = pTemp->pRight;
			}
			else
			{
				if(NULL == pTemp->pLeft)
				{
					pTemp->pLeft = pNewNode;
					break;
				}
				else
					pTemp = pTemp->pLeft;
			}
		}
	}
}

void InitQueue(struct node2 *pObj)
{
	pObj->iRear = pObj->iFront = -1;
}

int IsEmpty(struct node2 *pObj)
{
	if(pObj->iRear == pObj->iFront)
		return 1;
	return 0;
}

void EnQueue(struct node2 *pObj,struct node1 *pNewNode)
{
	pObj->Nodes[++pObj->iRear] = pNewNode;
}

struct node1 * DeQueue(struct node2 *pObj)
{
	return (pObj->Nodes[++pObj->iFront]);
}

int Level(struct node1 *pRoot,int iVertices)
{
	int iLevel = 0;
	struct node2 Obj;
	struct node1 *pTemp = NULL;
	struct node1 * pMarker = NULL;
	
	InitQueue(&Obj);
	EnQueue(&Obj,pRoot);
	EnQueue(&Obj,pMarker);
	
	printf("\nLevel %d :-\t",iLevel);
	
	while(!IsEmpty(&Obj))
	{
		pTemp = DeQueue(&Obj);
		
		if(pMarker == pTemp)
		{
			iLevel++;
			
			EnQueue(&Obj,pMarker);
			
			if(iVertices == iLevel)
				break;
			
			printf("\nLevel %d :-\t",iLevel);
		}
		else
		{
			printf("%d\t",pTemp->iData);
			
			if(pTemp->pLeft != NULL)
				EnQueue(&Obj,pTemp->pLeft);
			
			if(pTemp->pRight != NULL)
				EnQueue(&Obj,pTemp->pRight);
		}
	}
	
	printf("\n\nTotal Levels => %d\n",iLevel);
	
	return iLevel;
}

int NodesAtLevel(struct node1 *pRoot,int iLevel)
{
	if(NULL == pRoot)
		return 0;
	else if(0 == iLevel)
		return 1;
		
	return (NodesAtLevel(pRoot->pLeft,iLevel-1)+NodesAtLevel(pRoot->pRight,iLevel-1));
}

/* 
	O/P:-	
		Enter Total Number Of Vertices:-        3

		Enter Vertex 1:-        1

		Enter Vertex 2:-        2

		Enter Vertex 3:-        3

		Level 0 :-      1
		Level 1 :-      2
		Level 2 :-      3

		Total Levels => 3

		Total Nodes At Level 0:-        1
		Total Nodes At Level 1:-        1
		Total Nodes At Level 2:-        1
*/
