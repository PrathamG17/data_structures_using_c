#include <stdio.h>

void BFS(int);

int Rear = -1;
int Front;
int Vertices;
int Queue[10];
int Visited[10];
int GraphMatrix[10][10];

int main(void)
{
	int Source;
	int Counter1;
	int Counter2;
	
	printf("\nEnter Total No. of Vertices :\t");			
	scanf("%d",&Vertices);
	//ABOVE:- vertices ghetle..
	
	printf("\nEnter Graph Matrix :-\n");
	for(Counter1 = 1; Counter1 <= Vertices; Counter1++)
	{
		for(Counter2 =  1; Counter2 <= Vertices; Counter2++)
			scanf("%d",&GraphMatrix[Counter1][Counter2]);
	}
	//ABOVE:- graph ghetla in terms of adjacency matrix...
	
	printf("\nEnter Source Vertex :\t");
	scanf("%d",&Source);
	//ABOVE:- Source vertex ghetlaa..
	
	BFS(Source);
	//ABOVE:- BFS laa pathvala...
	
	printf("\nReachable Vertex Are:-\n");
	for(Counter1 = 1; Counter1 <= Vertices; Counter1++)
	{
		if(Visited[Counter1])
			printf("%d\t",Counter1);
		else
			printf("\nBFS Not Possible.\n");
	}
	
	return 0;
}

void BFS(int Source)
{
	int Counter;
		
	for(Counter = 1; Counter <= Vertices; Counter++)
	{
		if(GraphMatrix[Source][Counter] && (! Visited[Counter]))
			Queue[++Rear] = Counter;
		/*
		ABOVE:-
		-->if(GraphMatrix[Source][Counter] && (! Visited[Counter]))..
		jar source cha adjacent asel tar && cha pahila operand (1 i.e.true ) asel aani to adjacent visited madhe nasel (i.e. visited[Counter] zero asnar mag te.. Logical Not (!) lavun && cha dusara operand pan (1 i.e. true mhnanaar..) 
		-->mag aat madhe yeun tya adjacent laa queue madhe takla...(queue madhe Rear kadun taktat aani Front kadun kadhtat aani initially Rear =-1 mhnun aadhi ++ mag Rear madhali value var) adjacent queue madhe thevlaa..)
		*/
		if(Front <= Rear)	//jar queue empty nasel tar (i.e. Front <= Rear)
		{
			Visited[Queue[Front]] = 1;
			
			BFS(Queue[Front++]);
		}
		/*
		ABOVE:-Queue madhe taklelya element cha as a index mhnun vaapar kela aani tya index la visited array madhe 1 mhnatla..mhnje to visit jhala...aani mag BFS laa call kelay tevha pan jo visit jhlay to BFS laa pahila pathvala mag Front++ kelay...mhnje..Qeue pudhe sarkla..
		*/
	}
}
