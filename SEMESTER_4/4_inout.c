#include <stdio.h>
#include<malloc.h>

void DisplayList(int);
void CreateList(int Matrix[10][10],int);
void GraphDegree(int Matrix[10][10],int);
void CreateMatrix(int Matrix[10][10],int);
void DisplayMatrix(int Matrix[10][10],int);

struct node
{
	int Vertex;
	struct node *Next;
};

struct node *List[10] ={NULL};

int main(void)
{
	int Vertices;
	int Matrix[10][10];
	
	printf("\nEnter vertices :\t");
	scanf("%d",&Vertices);
	
	CreateMatrix(Matrix,Vertices);
	
	DisplayMatrix(Matrix,Vertices);
	
	CreateList(Matrix,Vertices);
	
	DisplayList(Vertices);
	
	GraphDegree(Matrix,Vertices);
	
	return 0;
}

void CreateMatrix(int Matrix[10][10],int Vertices)
{
	int Counter1;
	int Counter2;
	
	for(Counter1 = 0; Counter1 < Vertices; Counter1++)
	{
		for(Counter2 = 0; Counter2 < Vertices; Counter2++)
		{
				Matrix[Counter1][Counter1] = 0;
				
				if(Counter1 != Counter2)
				{
					printf("\nIs There Any Edge Between %d & %d (1/0):",Counter1+1,Counter2+1);
					scanf("%d",&Matrix[Counter1][Counter2]);
				}
		}
	}
}

void DisplayMatrix(int Matrix[10][10],int Vertices)
{
	int Counter1;
	int Counter2;
	
	printf("\nAdjacency Matrix :\n");
	
	for(Counter1 = 0; Counter1 < Vertices; Counter1++)
	{
		for(Counter2 = 0; Counter2 < Vertices;Counter2++)
		{
			printf("%d\t",Matrix[Counter1][Counter2]);
		}
		
		printf("\n");
	}
}

void CreateList(int Matrix[10][10],int Vertices)
{
	int Counter1;
	int Counter2;
	struct node *NewNode = NULL;
	struct node *Temp = NULL;
	
	for(Counter1 = 0; Counter1 < Vertices; Counter1++)
	{
		List[Counter1] = NULL;
		
		for(Counter2 = 0; Counter2 < Vertices; Counter2++)
		{
			if(1 == Matrix[Counter1][Counter2])
			{
				NewNode = (struct node *)malloc(sizeof(struct node));
				NewNode->Vertex = Counter2+1;
				NewNode->Next = NULL;
				
				if(NULL == List[Counter1])
				{
					List[Counter1] = Temp = NewNode;
				}
				else
				{
					Temp->Next = NewNode;
					Temp = NewNode;
				}
			}
		}
	}
}

void DisplayList(int Vertices)
{
	int Counter;
	struct node *Temp = NULL;
	
	printf("\nAdjacency List:\n");
	for(Counter = 0; Counter < Vertices; Counter++)
	{
		printf("\nV%d-->",Counter+1);
		
		Temp = List[Counter];
		
		while(Temp)
		{
			printf("V%d-->",Temp->Vertex);
			Temp = Temp->Next;
		}
		
		printf("NULL");
	}
}

void GraphDegree(int Matrix[10][10],int Vertices)
{
	int Counter1;
	int Counter2;
	int Indegree;
	int Outdegree;
	
	printf("\nVertex\tInedgree\tOutdegree\tDegreeVertex\n");
	for(Counter1 = 0; Counter1 < Vertices; Counter1++)
	{
		Indegree = Outdegree = 0;
		
		for(Counter2 = 0; Counter2 < Vertices; Counter2++)
		{
			Indegree = Indegree + Matrix[Counter1][Counter2];
			Outdegree = Outdegree + Matrix[Counter2][Counter1];
		}
		
		printf("\n%d\t\t%d\t\t%d\t\t%d",Counter1+1,Indegree,Outdegree,Indegree+Outdegree);
	}
	
}
/* 
	O/P:-
		
		Enter vertices :        4

		Is There Any Edge Between 1 & 2 (1/0):1

		Is There Any Edge Between 1 & 3 (1/0):1

		Is There Any Edge Between 1 & 4 (1/0):0

		Is There Any Edge Between 2 & 1 (1/0):0

		Is There Any Edge Between 2 & 3 (1/0):1

		Is There Any Edge Between 2 & 4 (1/0):1

		Is There Any Edge Between 3 & 1 (1/0):1

		Is There Any Edge Between 3 & 2 (1/0):1

		Is There Any Edge Between 3 & 4 (1/0):0

		Is There Any Edge Between 4 & 1 (1/0):0

		Is There Any Edge Between 4 & 2 (1/0):0

		Is There Any Edge Between 4 & 3 (1/0):0

		Adjacency Matrix :
		0       1       1       0
		0       0       1       1
		1       1       0       0
		0       0       0       0

		Adjacency List:

		V1-->V2-->V3-->NULL
		V2-->V3-->V4-->NULL
		V3-->V1-->V2-->NULL
		V4-->NULL
		Vertex  Inedgree        Outdegree       DegreeVertex

		1               2               1               3
		2               2               2               4
		3               2               2               4
		4               0               1               1

*/