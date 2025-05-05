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

void Display(struct Vertex *pHead);
void DeleteAll(struct Vertex **ppHead);
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
		printf("\n-->HOW MANY ADJACENT VERTEX FOR %d:  ",pTemp1->iNo);
		scanf("%d",&iAdjCount);
		InsertEdge(pTemp1,iAdjCount);
		
		pTemp2=pTemp1->pAdjEdge;
		while(pTemp2 != NULL)
		{
			printf("\n\tENTER ADJACENT VERTEX = ");
			scanf("%d",&iAdjVertex);
			
			pTemp3=pFirst;
			while(pTemp3 != NULL)
			{
				if(iAdjVertex == pTemp3->iNo)
					break;
				pTemp3=pTemp3->pNextVertex;
			}
			
			if(NULL == pTemp3)
				pTemp3=InsertVertex(&pFirst,iAdjVertex);
			
			pTemp2->pAdjVertex=pTemp3;				
			pTemp2=pTemp2->pNextEdge;
		}
		
		pTemp1=pTemp1->pNextVertex;
		if(NULL == pTemp1)
			break;
	}
	
	printf("\nGRAPH IS...");
	Display(pFirst);

	if(pFirst != NULL)
	{
		DeleteAll(&pFirst);
		pFirst=NULL;
	}
	
	return 0;
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
	pNewNode->pNextVertex=NULL;
	pNewNode->pAdjEdge=NULL;
	
	if(NULL == *ppHead)
		*ppHead=pNewNode;
	else
	{
		pTemp=*ppHead;
		while(pTemp->pNextVertex != NULL)
			pTemp=pTemp->pNextVertex;
		pTemp->pNextVertex=pNewNode;
	}
	
	return pNewNode;
}
void InsertEdge(struct Vertex *pHead,int iAdjCount)
{
	int iCounter;
	struct Edge *pTemp=NULL;
	struct Edge *pNewNode=NULL;
	
	for(iCounter=0 ; iCounter < iAdjCount ; iCounter++)
	{
		pNewNode=(struct Edge *)malloc(sizeof(struct Edge));
		if(NULL == pNewNode)
		{
			printf("MEMORY ALLOCATION FAILED\n");
			return;
		}
		
		pNewNode->pAdjVertex=NULL;
		pNewNode->pNextEdge=NULL;
		
		if(NULL == pHead->pAdjEdge)
			pHead->pAdjEdge=pNewNode;
		else
		{
			pTemp=pHead->pAdjEdge;
			while(pTemp->pNextEdge != NULL)
				pTemp=pTemp->pNextEdge;
			pTemp->pNextEdge=pNewNode;
		}
	}
}
void Display(struct Vertex *pHead)
{
	struct Edge *pTemp=NULL;
	
	while(pHead != NULL)
	{
		printf("\n%d = ",pHead->iNo);
		pTemp=pHead->pAdjEdge;
		while(pTemp != NULL)
		{
			printf("-->>%d",pTemp->pAdjVertex->iNo);
			pTemp=pTemp->pNextEdge;
		}
		pHead=pHead->pNextVertex;
	}
}
void DeleteAll(struct Vertex **ppHead)
{
	struct Vertex *pTemp1=NULL;
	struct Edge *pTemp2=NULL;
	struct Edge *pTemp3=NULL;
	
	while(*ppHead != NULL)
	{
		pTemp2=(*ppHead)->pAdjEdge;
		while(pTemp2 != NULL)
		{
			pTemp3=pTemp2;
			pTemp2=pTemp3->pNextEdge;
			
			pTemp3->pAdjVertex=NULL;
			pTemp3->pNextEdge=NULL;
			free(pTemp3);
			pTemp3=NULL;
		}
		
		pTemp1=*ppHead;
		*ppHead=pTemp1->pNextVertex;
		
		pTemp1->pAdjEdge=NULL;
		pTemp1->pNextVertex=NULL;
		free(pTemp1);
		pTemp1=NULL;
	}
}
