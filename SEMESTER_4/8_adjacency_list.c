#include <stdio.h>
#include <malloc.h>

void InsertAdjList(int);
void DisplayList(int);

struct node
{
	int iAdjVertex;
	struct node *pNext;
};

struct node *AdjacencyList[10] = {NULL};

int main(void)
{
	int iVertices;
	
	printf("\nEnter Total Number Of Vertex :\t");
	scanf("%d",&iVertices);
	
	InsertAdjList(iVertices);
	
	DisplayList(iVertices);
	
	return 0;
}

void InsertAdjList(int iVertices)
{
	int iVertex;
	int iAdjSize;
	int iCounter1;
	int iCounter2;
	struct node *pLast = NULL;
	struct node *pNewNode = NULL;
	
	for(iCounter1 = 0; iCounter1 < iVertices; iCounter1++)
	{
		printf("\nHow Many Number Of Adjacent Vertices For Vertex %d:\t",iCounter1+1);
		scanf("%d",&iAdjSize);
		
		for(iCounter2 = 0; iCounter2 < iAdjSize; iCounter2++)
		{
			printf("\nEnter %d Adjacent Vertex to %d:\t",iCounter2+1,iCounter1+1);
			scanf("%d",&iVertex);
			
			pNewNode = (struct node *)malloc(sizeof(struct node));
			if(NULL == pNewNode)
			{
				printf("\nMemory Allocation Failed\n");
				return;
			}
			
			pNewNode->iAdjVertex = iVertex;
			pNewNode->pNext = NULL;
			
			if(NULL == AdjacencyList[iCounter1])
				AdjacencyList[iCounter1] = pNewNode;
			else
				pLast->pNext = pNewNode;
			
			pLast = pNewNode;
		}	
	}
}

void DisplayList(int iVertices)
{
	int iCounter;
	struct node *pTemp = NULL;
	
	for(iCounter = 0; iCounter < iVertices; iCounter++)
	{
		printf("\n\nAdjacent Vertex To %d:-\t",iCounter+1);
		
		pTemp = AdjacencyList[iCounter];
		while(pTemp != NULL)
		{
			printf("%d\t",pTemp->iAdjVertex);
			pTemp = pTemp->pNext;
		}
		
		printf("\n");
	}
}
/*  
	O/P:-
		
		Enter Total Number Of Vertex :  4

		How Many Number Of Adjacent Vertices For Vertex 1:      3

		Enter 1 Adjacent Vertex to 1:   2

		Enter 2 Adjacent Vertex to 1:   3

		Enter 3 Adjacent Vertex to 1:   4

		How Many Number Of Adjacent Vertices For Vertex 2:      2

		Enter 1 Adjacent Vertex to 2:   1

		Enter 2 Adjacent Vertex to 2:   4

		How Many Number Of Adjacent Vertices For Vertex 3:      2

		Enter 1 Adjacent Vertex to 3:   1

		Enter 2 Adjacent Vertex to 3:   4

		How Many Number Of Adjacent Vertices For Vertex 4:      3

		Enter 1 Adjacent Vertex to 4:   1

		Enter 2 Adjacent Vertex to 4:   2

		Enter 3 Adjacent Vertex to 4:   3


		Adjacent Vertex To 1:-  2       3       4

		Adjacent Vertex To 2:-  1       4

		Adjacent Vertex To 3:-  1       4

		Adjacent Vertex To 4:-  1       2       3

*/