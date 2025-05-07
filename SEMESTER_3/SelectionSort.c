#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void SelectionSort(int Arr1[],int Size1);
void CreateArray(int[],int);
void Display(int[],int);
int main()
{
	int Arr[MAX],Size;
	printf("\nPLEASE ENTER HOW MANY ELEMENTS YOU WANT TO ENTER:\t");
	scanf("%d",&Size);
	CreateArray(Arr,Size);
	printf("\nYOUR ARRAY\n\n");
	Display(Arr,Size);
	SelectionSort(Arr,Size);
	printf("\n\nYOUR SORTED ARRAY\n\n");
	Display(Arr,Size);
	return 0;
}
void SelectionSort(int Arr1[],int Size1)
{
	int Min,i,j,Temp;
	for (i=0;i<(Size1-1);i++)
	{
		Min = i;
		for (j=i+1;j<Size1;j++)
		{
			if (Arr1[j]<Arr1[Min])
				Min= j;
		}
		if (Min!=i)
		{
			Temp=Arr1[i];
			Arr1[i]=Arr1[Min];
			Arr1[Min]=Temp;
		}
	}
}
void CreateArray(int Arr1[],int Size1)
{
	int i;
	for(i=0;i<Size1;i++)
		Arr1[i]=rand()%100;
}
void Display(int Arr1[],int Size1)
{
	int i;
	for(i=0;i<Size1;i++)
			printf("\nElement No %d:\t%d",i+1,Arr1[i]);
}