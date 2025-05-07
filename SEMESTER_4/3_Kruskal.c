#include <stdio.h>

int Find(int);
int Uni(int,int);

int Counter1;
int Counter2;
int Parent[10];

int main(void)
{
	int K;
	int A;
	int B;
	int U;
	int V;	
	int Min;
	int Vertices;
	int CostMatrix[10][10];
	int MinCost = 0;
	int NoEdges = 1;

	printf("\nEnter vetices :\t");
	scanf("%d",&Vertices);
	
	printf("\nEnter Cost Adjacency Matrix :\n");
	for(Counter1 = 1, Min = 999; Counter1 <= Vertices; Counter1++)
	{
		for(Counter2 = 1; Counter2 <= Vertices; Counter2++)
		{
			scanf("%d",&CostMatrix[Counter1][Counter2]);
			
			if(0 == CostMatrix[Counter1][Counter2])
				CostMatrix[Counter1][Counter2] = 999;
		}
	}
	
	printf("\nEdges with minimum cost are :\n");
	
	while(NoEdges < Vertices)
	{
		for(Counter1 = 0,Min = 999; Counter1 <= Vertices; Counter1++)
		{
			for(Counter2 = 1; Counter2 <= Vertices; Counter2++)
			{
				if(CostMatrix[Counter1][Counter2] < Min)
				{
					Min = CostMatrix[Counter1][Counter2];
					A = U = Counter1;
					B = V = Counter2;
				}
			}
		}
		
		U = Find(U);
		V = Find(V);
		
		if(Uni(U,V))
		{
			printf("\nEdges %d : (%d  %d) cost :- %d\n",NoEdges++,A,B,Min);
			MinCost = MinCost + Min;
		}
		
		CostMatrix[A][B] = CostMatrix[B][A] = 999;
	}
	
	printf("\nMinimum cost is %d\n",MinCost);
	
	return 0;
}

int Find(int Counter1)
{
	while(Parent[Counter1])
		Counter1 = Parent[Counter1];
	
	return Counter1;
}

int Uni(int Counter1, int Counter2)
{
	if(Counter1 != Counter2)
	{
		Parent[Counter2] = Counter1;
		
		return 1;
	}
	
	return 0;
}
/*  
	O/P:-
		Enter vetices : 4

		Enter Cost Adjacency Matrix :
		0 2 6 4
		2 0 0 3
		6 0 0 5
		4 3 5 0

		Edges with minimum cost are :

		Edges 1 : (1  2) cost :- 2

		Edges 2 : (2  4) cost :- 3

		Edges 3 : (3  4) cost :- 5

		Minimum cost is 10

*/