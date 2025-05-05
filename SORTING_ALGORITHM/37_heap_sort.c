#include<stdio.h>
#define MAX 20
int Set(int Data[],int *iSize);
void Display(int Data[],int iSize);
void HeapSort(int Data[],int iSize);
void BuildHeapTree(int Data[],int iSize);
void Restore(int Data[],int iNode,int iSize);
int main(void)
{
	int Data[MAX]={0};
	int iCounter;
	int iSize;
	
	printf("HOW MANY NUMBER OF ELEMENTS YOU WANT TO ENTER(<20):\t");
	scanf("%d",&iSize);
	
	printf("\n-----ENTER YOUR %d NUMBERS-----\n",iSize);
	for(iCounter=1 ; iCounter<=iSize ; iCounter++)
	{
		printf("\tENTER NUMBER %d:",iCounter);
		scanf("%d",&Data[iCounter]);
	}
	
	HeapSort(Data,iSize);
	
	printf("\n-----YOUR SORTED DATA-----\n");
	Display(Data,iSize);
	
	return 0;
}
void HeapSort(int Data[],int iSize)
{
	int iMax;
	int iCounter;
	
	BuildHeapTree(Data,iSize);
	
	printf("\n------HEAP TREE------\n");
	Display(Data,iSize);
	
	while(iSize>1)
	{
		iMax=Set(Data,&iSize);
		Data[iSize+1]=iMax;
	}
}
void BuildHeapTree(int Data[],int iSize)
{
	int iCounter;
	
	for(iCounter=iSize/2 ; iCounter>=1 ; iCounter--)
		Restore(Data,iCounter,iSize);
}
void Restore(int Data[],int iNode,int iSize)
{
	int iLeft;
	int iRight;
	int iTemp;
	
	iLeft=iNode*2;
	iRight=iLeft+1;
	
	iTemp=Data[iNode];
	while(iRight<=iSize)
	{
		if(iTemp>Data[iLeft] && iTemp>Data[iRight])
		{
			Data[iNode]=iTemp;
			return;
		}
		else if(Data[iLeft]>Data[iRight])
		{
			Data[iNode]=Data[iLeft];
			iNode=iLeft;
		}
		else
		{
			Data[iNode]=Data[iRight];
			iNode=iRight;
		}
		iLeft=iNode*2;
		iRight=iLeft+1;	
	}
	if(iLeft==iSize && Data[iLeft]>Data[iNode])
	{
		Data[iNode]=Data[iLeft];
		iNode=iLeft;
	}
	Data[iNode]=iTemp;
}
int Set(int Data[],int *iSize)
{
	int iMax;
	
	iMax=Data[1];
	Data[1]=Data[*iSize];
	(*iSize)--;
	Restore(Data,1,*iSize);
	return iMax;
}
void Display(int Data[],int iSize)
{
	int iCounter;
	
	for(iCounter=1 ; iCounter<=iSize ; iCounter++)
		printf("%d\t",Data[iCounter]);
}
