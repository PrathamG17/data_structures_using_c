/* 
	yaaat fakt for loop che counter check kar...
*/
#include <stdio.h>

void Path(void);
int Min(int,int);

int Size;
int Arr[10][10];
int Distance[10][10];

int main(void)
{
	int Counter1;
	int Counter2;
	
	printf("\nEnter Size:\t");
	scanf("%d",&Size);
	
	printf("\nEnter Matrix:\n");
	for(Counter1 = 0; Counter1 < Size; Counter1++)
	{
		for(Counter2 = 0; Counter2 < Size; Counter2++)
		{
			scanf("%d",&Arr[Counter1][Counter2]);
			Distance[Counter1][Counter2] = Arr[Counter1][Counter2];
		}
	}
	
	Path();
	
	printf("\nDistance Matrix is:\n");
	for(Counter1 = 0; Counter1 < Size; Counter1++)
	{
		for(Counter2 = 0; Counter2 < Size; Counter2++)
		{
			printf("%d\t",Distance[Counter1][Counter2]);
		}
		printf("\n");
	}
	
	return 0;
}

void Path(void)
{
	int i;
	int j;
	int k;
	
	for(k = 0; k < Size; k++)
	{
		for(i = 0; i < Size; i++)
		{
			for(j = 0; j < Size; j++)
			{
				Distance[i][j] = Min(Distance[i][j],Distance[i][k]+Distance[k][j]);
			}
		}
	}
}

int Min(int No1,int No2)
{
	if(No1 < No2)
		return No1;
	else
		return No2;
}

/* 
	O/P:-
		
		Enter Size:     4

		Enter Matrix:
		0 2 6 4
		2 0 0 3
		6 0 0 5
		4 3 5 0

		Distance Matrix is:
		0       2       2       4
		2       0       0       3
		2       0       0       3
		4       3       3       0

*/