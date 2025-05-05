#include<stdio.h>
#include<malloc.h>

struct Edge;
struct Vertex
{
	struct Vertex *pNextVertex;
	int iNo;
	struct Edge *pAdjEdge;
};
struct Edge
{
	struct Vertex *pAdjVertex;
	struct Edge *pNextEdge;
};

//void DeleteAll(struct Vertex **ppHead);
void InsertEdge(struct Vertex *pHead,int iAdjCount);
struct Vertex* InsertVertex(struct Vertex **ppHead,int iData);

int main(void)
{
	int iData;
	int iAdjCount;
	int iAdjVertex;
	struct Edge *pTemp2=NULL;
	struct Vertex *pTemp3=NULL;
	struct Vertex *pTemp1=NULL;
	struct Vertex *pFirst=NULL;
	
	printf("ENTER VERTEX:\t");
	scanf("%d",&iData);
	
	pTemp1=InsertVertex(&pFirst,iData);
	while(pTemp1->pAdjEdge == NULL)
	{
		printf("\nHOW MANY ADJACENT VERTEX FOR %d:\t",pTemp1->iNo);
		scanf("%d",&iAdjCount);
		InsertEdge(pTemp1,iAdjCount);
		
		pTemp2=pTemp1->pAdjEdge;
		while(pTemp2 != NULL)
		{
			printf("\nENTER ADJACENT VERTEX = ");
			scanf("%d",&iAdjVertex);
			
			pTemp3=pFirst;
			while(pTemp3 != NULL)
			{
				if(iAdjVertex == pTemp3->iNo)
					break;
				pTemp3=pTemp3->pNextVertex;
			}
			
			if(NULL == pTemp3)
				pTemp2->pAdjVertex=InsertVertex(&pFirst,iAdjVertex);
			else
				pTemp2->pAdjVertex=pTemp3;
				
			pTemp2=pTemp2->pNextEdge;
		}
		
		pTemp1=pTemp1->pNextVeretx;
		
		if(NULL == pTemp1)
			break;
	}
}
struct Vertex* InsertVertex(struct Vertex **ppHead,int iData)
{
	struct Vertex *pNewNode=NULL;
	struct Vertex *pTemp=NULL;
	
	pNewNode=(struct Vertex *)malloc(sizeof(struct Vertex));
	if(NULL == pNewNode)
	{
		printf("MEMORY ALLOCATION FAILED\n");
		return NULL;
	}
	
	pNewNode->iNo=iData;
	pNewNode->pNextVeretx=pNewNode->pAdjVertex=NULL;
	
	if(NULL == *ppHead)
		*ppHead=pNewNode;
	else
	{
		pTemp=*ppHead;
		while(pTemp->pNextVeretx != NULL)
			pTemp=pTemp->pNextVertex;
		pTemp->pNextVeretx=pNewNode;
	}
	
	return pNewNode;
}
void InsertEdge(struct Vertex *pHead,int iAdjCount)
{
	int iCounter;
	struct Edge *pNewNode=NULL;
	
	for(iCounter=0 ; iCounter < iAdjCount ; iCounter++)
	{
		pNewNode=(struct Edge *)malloc(sizeof(struct Edge));
		if(NULL == pNewNode)
		{
			printf("MEMORY ALLOCATION FAILED\n");
			return;
		}
		
		pNewNode->pAdjVertex=pNewNode->pNextEdge=NULL;
		
		if(NULL == pHead->pAdjEdge)
			pHead->pAdjEdge=pNewNode;
		else
		{
			pHead=pHead->pAdjEdge;
			while(pHead->pNextEdge != NULL)
				pHead=pHead->pNextEdge;
			pHead->pNextEdge=pNewNode;
		}
	}
}
