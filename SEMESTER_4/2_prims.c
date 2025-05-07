/* 
	1.vertices ghetle..
	2.cost matrix ghetlaa...aani ghetna jjithe zero hota...tithe infinite kela..
	3.number of edges chya condition nee...while loop chalavla..
	4. aat yenya purvi visited[1] = 1 karun newline dee...
	5.aat madhe...nested for loop lavun...Min laa pan Assign kar aani aaatlya for loop laa...madhe..
	check kar Min peksha lahana aahe ka? 
	6.asel tar...aaat tya Vertex cha Visited != zero aahe kaa bagh..ani asel tar Min madhe tyla taak...aani a,u aani b,v pan taakun ghe...
	7.pahila loop chya baher..visited u,v che check karun ...print kar edge , a,b,Min
	8.MinCost total kar
	9.Visited[b] = 1
	Cost[][] = Cost[][]
*/
#include <stdio.h>

int main(void)
{
	int a;
	int b;
	int u;
	int v;
	int Min;
	int iCounter1;
	int iCounter2;
	int MinCost = 0;
	int iVertices;
	int NoEdges = 1;
	int Visited[8] = {0};
	int CostMatrix[8][8] = {0};
	
	printf("\nEnter Total Vertices :-\n");
	scanf("%d",&iVertices);
	
	printf("\nEnter Cost Matrix:\n");
	for(iCounter1 = 0; iCounter1 < iVertices; iCounter1++)
	{
		for(iCounter2 = 0; iCounter2 < iVertices; iCounter2++)
		{
			scanf("%d",&CostMatrix[iCounter1][iCounter2]);
			
			if(0 == CostMatrix[iCounter1][iCounter2])
				CostMatrix[iCounter1][iCounter2] = 99;
		}
	}
	
	Visited[1] = 1;
	printf("\n");
	
	while(NoEdges < iVertices)
	{
		for(iCounter1 = 0,Min = 99; iCounter1 < iVertices; iCounter1++)
		{
			for(iCounter2 = 0; iCounter2 < iVertices; iCounter2++)
			{
				if(CostMatrix[iCounter1][iCounter2] < Min)
				{
					if(Visited[iCounter1] != 0)
					{
						Min = CostMatrix[iCounter1][iCounter2];
						a = u = iCounter1;
						b = v = iCounter2;
					}
				}	
			}			
		}
		if(0 == Visited[u] || 0 == Visited[v])
		{
			printf("\nEdge %d :(%d %d) Cost :- %d\n", NoEdges++, a, b, Min);
			MinCost = MinCost + Min;
			Visited[b] = 1;
		}
		
		CostMatrix[a][b] = CostMatrix[b][a] = 99;
	}
	
	printf("\n Minium Cost = %d\n",MinCost);
	return 0;
}
/* 
	O/p:-
		Enter Total Vertices :-
		4

		Enter Cost Matrix:
		0 2 6 4
		2 0 0 3
		6 0 0 5
		4 3 5 0


		Edge 1 :(1 0) Cost :- 2

		Edge 2 :(1 3) Cost :- 3

		Edge 3 :(3 2) Cost :- 5

		Minium Cost = 10
 
*/