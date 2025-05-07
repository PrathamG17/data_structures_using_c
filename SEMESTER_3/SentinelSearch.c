#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int SentinelSearch(int[],int,int);
void CreateArray(int[],int);
void Display(int[],int);
int main(void)
{
	int Arr[MAX],Size,Key,Position,Last;
	printf("\nPLEASE ENTER HOW MANY ELEMENTS YOU WANT TO ENTER:\t");
	scanf("%d",&Size);
	CreateArray(Arr,Size);
	Display(Arr,Size);
	printf("\n\nPLEASE ENTER THE ELEMENT WHICH YOU WANT TO SEARCH:\t");
	scanf("%d",&Key);
	Last=Arr[Size-1];
	Position=SentinelSearch(Arr,Size,Key);
	Arr[Size-1]=Last;
	if(Key==Arr[Position])
		printf("\n\n%d ELEMENT FOUND AT %dth LOCATION\n\n",Arr[Position],Position+1);
	else
		printf("\n\nELEMENT NOT FOUND\n\n");
	return 0;
}
int SentinelSearch(int Arr1[],int Size1,int Number)
{
	int i=0;
	Arr1[Size1-1]=Number;
	while(Number!=Arr1[i])
		i++;
	return i;
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
