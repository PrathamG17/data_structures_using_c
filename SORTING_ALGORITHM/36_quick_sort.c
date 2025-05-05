#include<stdio.h>
#define MAX 20
int Partition(int Data[],int iLow,int iUp);
void QuickSort(int Data[],int iLow,int iUp);
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
	
	QuickSort(Data,0,iSize-1);
	
	printf("\n-----YOUR SORTED DATA-----\n");
	for(iCounter=0 ; iCounter<iSize ; iCounter++)
		printf("%d\t",Data[iCounter]);
	printf("\n");
	
	return 0;
}
void QuickSort(int Data[],int iLow,int iUp)
{
	int iPivotLoc;
	
	if(iLow>=iUp)
		return;
	
	iPivotLoc=Partition(Data,iLow,iUp);
	QuickSort(Data,iLow,iPivotLoc-1);
	QuickSort(Data,iPivotLoc+1,iUp);
}
int Partition(int Data[],int iLow,int iUp)
{
	int iPivot;
	int iCounter1;
	int iCounter2;
	
	iPivot=Data[iLow];
	iCounter1=iLow+1;
	iCounter2=iUp;
	
	while(iCounter1<=iCounter2)
	{
		while(Data[iCounter1]<iPivot && iCounter1<iUp)
			iCounter1++;
		
		while(Data[iCounter2]>iPivot)			//------------------------------
			iCounter2--;
		
		if(iCounter1<iCounter2)
		{
			Data[iCounter1]=Data[iCounter1]+Data[iCounter2];
			Data[iCounter2]=Data[iCounter1]-Data[iCounter2];
			Data[iCounter1]=Data[iCounter1]-Data[iCounter2];
			iCounter1++;
			iCounter2--;
		}
		else
			iCounter1++;						//-------------------------------
	}
	
	Data[iLow]=Data[iCounter2];
	Data[iCounter2]=iPivot;
	
	return iCounter2;
}
