#include <stdio.h>

int main(void)
{
	int iVertices;
	int iEdges;
	int iCounter1;
	int iCounter2;
	int iVertex1;
	int iVertex2;
	int iAdjacencyMatrix[10][10] = {0};
	
	printf("\nEnter Total Number of Vertices :-\t");
	scanf("%d",&iVertices);
	
	printf("\nEnter Total Number Of Edges :-\t");
	scanf("%d",&iEdges);
	
	for(iCounter1 = 0; iCounter1 < iEdges; iCounter1++)
	{
		printf("\nEnter Edge %d In The Form Of(V1 V2) :-\t",iCounter1+1);
		scanf("%d%d",&iVertex1,&iVertex2);
		iAdjacencyMatrix[iVertex1-1][iVertex2-1] = iAdjacencyMatrix[iVertex2-1][iVertex1-1] = 1;
	}
	/* 
		ABOVE(23):- minus by 1 .. is because vertex can't be 0 i.e. Vertex0 hence as user Enter vertex1
					the array's first row come in picture and not going to be wasted..
	*/
	printf("\nGiven Graph Adjacency Matrix :-\n");
	
	for(iCounter1 = 0; iCounter1 < iVertices; iCounter1++)		
	{
		for(iCounter2  = 0; iCounter2 < iVertices; iCounter2++)
			printf("\t%d",iAdjacencyMatrix[iCounter1][iCounter2]);
		
		printf("\n");
	}
	/*
		O/P:-
			Enter Total Number of Vertices :-       3

			Enter Total Number Of Edges :-  3

			Enter Edge 1 In The Form Of(V1 V2) :-   1 2

			Enter Edge 2 In The Form Of(V1 V2) :-   1 3

			Enter Edge 3 In The Form Of(V1 V2) :-   2 3

			Given Graph Adjacency Matrix :-
					0       1       1
					1       0       1
					1       1       0

	*/
	return 0;
}
