/* 
	1. vertiices ghetle pahile..
	2. tya vertices chya madtine..adjacency matrix ghetla..
	3. topology laa call..
	4. tyat indegree laa call..
	5. mag.. indegree calculate keli column same theun aani row badlvun..
	6.mag zero indegree asli tar start madhe ghetla..
	7.nantar...mag kahi nahi..ek ek kadhat topological sort madhe takat tyach tyach row madhlyanchi indegree minus karat karat..aani start madhe janya yogya aahe kaa he pan check kela...
	8.shevti sort print kela..
*/

#include <stdio.h>

void Topology(void);
void IndegreeCalculation(void);

int Vertices;
int Indegree[10];
int Matrix[10][10];

int main(void)
{
	int Counter1;
	int Counter2;
	
	printf("\nEnter Vertices : \t");
	scanf("%d",&Vertices);									//Taking total no. of vertices
	
	printf("\nEnter Adjacency Matrix :\n");
	for(Counter1 = 0; Counter1 < Vertices; Counter1++)
	{
		for(Counter2 = 0; Counter2 < Vertices; Counter2++)
			scanf("%d",&Matrix[Counter1][Counter2]);		//receiving adjecency matrix of graph
		
		printf("\n");
	}
	
	Topology();												//call sort()
	
	return 0;
}

void Topology(void)
{
	int Counter1;
	int Counter2;
	int Start[10];
	int Top = -1;
	int TopologicalSort[10];
	int Index = 0;
	
	IndegreeCalculation();									//calculate indegree for each vertex
	
	for(Counter1 = 0; Counter1 < Vertices; Counter1++)
	{
		if(0 == Indegree[Counter1])
			Start[++Top] = Counter1;						
		
		//checking and creating collection of vertices having indegree 0 for starting topological sort
	}
	
	while(Top != -1)										//until indegree 0 vertices vanishes
	{
		Counter1 = Start[Top--];
		TopologicalSort[Index++] = Counter1;				//vertices sorted
		
		for(Counter2 = 0; Counter2 < Vertices; Counter2++)	
		{
			if(1 == Matrix[Counter1][Counter2])
			{
				Indegree[Counter2]--;						
				//decreasing indegree of adjacent vertices of sorted vertx
				
				if(0 == Indegree[Counter2])
					Start[++Top] = Counter2;
				//if indegree is 0 then inserted into 'start' for further sorting use
			}
		}
	}
	
	printf("\nTopological Sort is ...\t");
	for(Counter1 = 0; Counter1 < Vertices; Counter1++)
		printf("\t%d",TopologicalSort[Counter1]+1);			//print sorted vertices
}

void IndegreeCalculation(void)
{
	int Sum;
	int Counter1;
	int Counter2;
	
	for(Counter1 = 0; Counter1 < Vertices; Counter1++)
	{
		Sum = 0;
		
		for(Counter2 = 0; Counter2 < Vertices ; Counter2++)
			Sum = Sum + Matrix[Counter2][Counter1];			//calculating indegree by matrix
			
		Indegree[Counter1] = Sum; 							//assigning indegree
	}
}
/* 
	O/P:-
		
		Enter Vertices :        4

		Enter Adjacency Matrix :
		0 1 1 1

		0 0 0 1

		0 0 0 0

		0 0 1 0


		Topological Sort is ...         1       2       4       3

*/