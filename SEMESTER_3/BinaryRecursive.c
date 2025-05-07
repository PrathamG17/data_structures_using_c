#include<stdio.h>
#define MAX 100
int BinaryRecursive(int[],int,int,int);
void CreateArray(int[],int);
int main(void)
{
	int Arr[MAX],Size,Key,Position;
	printf("\nPLEASE ENTER HOW MANY ELEMENTS YOU WANT TO ENTER:\t");
	scanf("%d",&Size);
	CreateArray(Arr,Size);
	printf("\n\nPLEASE ENTER THE ELEMENT WHICH YOU WANT TO SEARCH:\t");
	scanf("%d",&Key);
	Position=BinaryRecursive(Arr,0,Size-1,Key);
	if(-1==Position)
		printf("\n\nELEMENT NOT FOUND\n");
	else
		printf("\n%d ELEMENT FOUND AT %dth LOCATION\n",Key,Position+1);
	return 0;
}
int BinaryRecursive(int Arr1[],int Lower,int Higher,int Number)
{
	int mid;
	if(Higher<Lower)
		return -1;
	mid=(Lower+Higher)/2;
	if(Number==Arr1[mid])
		return mid;
	else if (Number<Arr1[mid])
		BinaryRecursive(Arr1,Lower,mid-1,Number);
	else
		BinaryRecursive(Arr1,mid+1,Higher,Number);
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
