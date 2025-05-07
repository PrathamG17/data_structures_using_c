#include <stdio.h>

void DFS(int);

int GraphMatrix[10][10];
int Visited[10];
int Vertices;

int main(void)
{
	int Edges;
	int Source;
	int Vertex1;
	int Vertex2;
	int Counter1;
	
	printf("\nEnter No. of Vertices :\t");
	scanf("%d",&Vertices);
	
	printf("\nEnter No. of Edges :\t");
	scanf("%d",&Edges);
	
	printf("\nEnter The Edges in a format(Vertex1 Vertex2):\n");
	for(Counter1 = 0; Counter1 < Edges; Counter1++)
	{
		scanf("%d%d",&Vertex1,&Vertex2);
		GraphMatrix[Vertex1-1][Vertex2-1] = 1;
	}
	//ABOVE:- User kadun graph ghetala edges form madhe...
	
	printf("\nGraph is :-\n");
	for(Counter1 = 0; Counter1 < Vertices; Counter1++)
	{
		for(Edges = 0; Edges < Vertices; Edges++)
			printf("%d",GraphMatrix[Counter1][Edges]);
		
		printf("\n");
	}
	//ABOVE:- Mag yaa 'for()' loop ni to graph normal print kela...
	
	printf("\nEnter Source Vertex :\t");
	scanf("%d",&Source);
	//ABOVE:- DFS sathi source vertex ghetla user kadun...
	
	DFS(Source-1);
	/*ABOVE:- varati graph ghetna (Vertex-1) asa store kelay matrix madhe mhnun source ekane minus krun DFS la pathvalay...*/
	
	return 0;
}

void DFS(int Source)
{
	int Counter1;
	
	Visited[Source] = 1;	
	//ABOVE:- Source laa visited madhe takla..
	
	printf("%d-->",Source+1);
	/*ABOVE:- user sathi sagla je kahi chalaay te (source+1) ne chalay mhnun pahila aalya aalya ithe tyla source print karun dila..*/
	
	for(Counter1 = 0; Counter1 < Vertices; Counter1++)
	{
		if((1 == GraphMatrix[Source][Counter1]) && (0 == Visited[Counter1]))
			DFS(Counter1);
	}
	/*ABOVE:- Mag 'for()' loop madhe yaa sathi yaych ki jar tya 
		source cha counter1 change hotoy mhnje.. row constant during iteration and column change means adjacent koni asel(i.e. == 1 asel) tar aani jo adjacent aahe to jar visited madhe nasel (i.e. 0 == Visisted[Counter1]) tarach aapan DFS function la call kartoy tya adhacent la pathvun ...
		mhnje ata tyacha DFS
	*/
}
