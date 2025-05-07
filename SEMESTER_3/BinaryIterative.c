#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int BinaryIterative(int[],int,int);
void CreateArray(int[],int);
int main(void)
{
	int Arr[MAX],Size,Key,Position;
	printf("\nPLEASE ENTER HOW MANY ELEMENTS YOU WANT TO ENTER:\t");
	scanf("%d",&Size);
	CreateArray(Arr,Size);
	printf("\n\nPLEASE ENTER THE ELEMENT WHICH YOU WANT TO SEARCH:\t");
	scanf("%d",&Key);
	Position=BinaryIterative(Arr,Size,Key);
	if(-1==Position)
		printf("\n\nELEMENT NOT FOUND\n");
	else
		printf("\n%d ELEMENT FOUND AT %dth LOCATION\n",Key,Position+1);
	return 0;
}
int BinaryIterative(int Arr1[MAX],int Size1,int Number)
{
	int Lower=0,Higher,Mid;
	Higher=Size1-1;
	while(Lower<=Higher)
	{
		Mid=(Lower+Higher)/2;
		if(Number==Arr1[Mid])
			return Mid;
		else if(Number<Arr1[Mid])
			Higher=Mid-1;
		else
			Lower=Mid+1;
	}
	return -1;
}
void CreateArray(int Arr1[],int Size1)
{
	int i;
	printf("\nPLEASE ENTER YOUR %d ELEMENTS\n\n",Size1);
	for(i=0;i<Size1;i++)
	{
		printf("ELEMENT NUMBER %d:\t",i+1);
		scanf("%d",&Arr1[i]);
	}
}
