#include<stdio.h>
#define MAX 20
void BubbleSort(int Data[],int iSize);
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
	
	BubbleSort(Data,iSize);
	
	printf("\n-----YOUR SORTED DATA-----\n");
	for(iCounter=0 ; iCounter<iSize ; iCounter++)
		printf("%d\t",Data[iCounter]);
	
	return 0;
}
void BubbleSort(int Data[],int iSize)
{
	int iCounter1;
	int iCounter2;
	int iSwaps;
	
	for(iCounter1=0 ; iCounter1<iSize-1 ; iCounter1++)
	{
		iSwaps=0;
		
		for(iCounter2=0 ; iCounter2<iSize-1-iCounter1 ; iCounter2++)
		{
			if(Data[iCounter2+1]<Data[iCounter2])
			{
				Data[iCounter2+1]=Data[iCounter2+1]+Data[iCounter2];
				Data[iCounter2]=Data[iCounter2+1]-Data[iCounter2];
				Data[iCounter2+1]=Data[iCounter2+1]-Data[iCounter2];
				iSwaps++;
			}
		}
		
		if(0==iSwaps)
			break;
	}
}
