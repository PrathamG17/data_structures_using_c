#include<stdio.h>
#define MAX 20
void InsertionSort(int Data[],int iSize);
int main(void)
{
	int Data[MAX]={0};
	int iCounter;
	int iSize;
	
	printf("HOW MANY NUMBER OF ELEMENTS YOU WANT TO ENTER(<20):\t");
	scanf("%d",&iSize);
	
	printf("\n-----ENTER YOUR %d NUMBERS-----\n",iSize);
	for(iCounter=0 ; iCounter<iSize ; iCounter++)
	{
		printf("\tENTER NUMBER %d:",iCounter+1);
		scanf("%d",&Data[iCounter]);
	}
	
	InsertionSort(Data,iSize);
	
	printf("\n-----YOUR SORTED DATA-----\n");
	for(iCounter=0 ; iCounter<iSize ; iCounter++)
		printf("%d\t",Data[iCounter]);
	
	return 0;
}
void InsertionSort(int Data[],int iSize)
{
	int iMin;
	int iCounter1;
	int iCounter2;
	
	for(iCounter1=0 ; iCounter1<iSize ; iCounter1++)
	{
		iMin=Data[iCounter1];
		
		for(iCounter2=iCounter1-1 ; iCounter2>=0 && iMin<Data[iCounter2] ; iCounter2--)
			Data[iCounter2+1]=Data[iCounter2];
		
		Data[iCounter2+1]=iMin;
	}
}
