#include <stdio.h>

void Dijikstras(int,int,int CostMatrix[10][10],int Distance[10]);

int main(void)
{
	int Size;
	int Vertex;
	int CostMatrix[10][10];
	int Distance[10];
	int Counter1;
	int Counter2;
	
	printf("\nEnter Size:\t");
	scanf("%d",&Size);
	
	printf("\nEnter Cost Matrix:\n");
	for(Counter1 = 1; Counter1 <= Size; Counter1++)
	{
		for(Counter2 = 1; Counter2 <= Size; Counter2++)
		{
			scanf("%d",&CostMatrix[Counter1][Counter2]);
			
			if(0 == CostMatrix[Counter1][Counter2])
				CostMatrix[Counter1][Counter2] = 999;
		}
	}
	
	printf("\nEnter Source Vertex : \t");
	scanf("%d",&Vertex);
	
	Dijikstras(Size,Vertex,CostMatrix,Distance);
	
	printf("\nShortest Path\n");
	for(Counter1 = 1; Counter1 <= Size; Counter1++)
	{
		if(Vertex != Counter1)
		{
			printf("\n%d-->%d Cost :- %d",Vertex,Counter1,Distance[Counter1]);
		}
	}
	
	return 0;
}

void Dijikstras(int Size,int Vertex,int CostMatrix[10][10],int Distance[10])
{
	int i;
	int u;
	int w;
	int Count;
	int Min;
	int Flag[10];
	
	for(i = 1; i <= Size; i++)
	{
		Flag[i] = 0;
		Distance[i] = CostMatrix[Vertex][i];
	}
	
	Count = 2;
	
	while(Count <= Size)
	{
		Min = 99;
		
		for(w = 1; w <= Size; w++)
		{
			if(Distance[w] < Min && !Flag[w])
			{
				Min = Distance[w];
				u = w;
			}
		}
		
		Flag[u] = 1;
		Count++;
		
		for(w = 1; w <= Size; w++)
		{
			if((Distance[u] + CostMatrix[u][w] < Distance[w]) && !Flag[w])
				Distance[w] = Distance[u] + CostMatrix[u][w];
		}
	}
}
/*  
	O/P:-
		
		Enter Size:     4

		Enter Cost Matrix:
		99 2 5 4
		99 99 99 3
		99 99 99 99
		99 99 6 99

		Enter Source Vertex :   1

		Shortest Path

		1-->2 Cost :- 2
		1-->3 Cost :- 5
		1-->4 Cost :- 4

*/

/*  
	99 mhnje tithe edge nahi ...tar te infinite dakhavylaa...tasa input dee...
*/