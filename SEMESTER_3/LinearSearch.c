#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int LinearSearch(int[],int,int);
void CreateArray(int[],int);
void Display(int[],int);
int main(void)
{
	int Arr[MAX],Size,Key,Position;
	printf("\nPLEASE ENTER HOW MANY ELEMENTS YOU WANT TO ENTER:\t");
	scanf("%d",&Size);
	CreateArray(Arr,Size);
	Display(Arr,Size);
	printf("\n\nPLEASE ENTER THE ELEMENT WHICH YOU WANT TO SEARCH:\t");
	scanf("%d",&Key);
	Position=LinearSearch(Arr,Size,Key);
	if(-1==Position)
		printf("\n\nELEMENT NOT FOUND\n");
	else
		printf("\n\n%d ELEMENT FOUND AT %dt LOCATION\n\n",Arr[Position],Position+1);
	return 0;
}
int LinearSearch(int Arr1[],int Size1,int Number)
{
	int i;
	for(i=0;i<Size1;i++)
	{
		if(Number==Arr1[i])
			return i;
	}
	return -1;
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
