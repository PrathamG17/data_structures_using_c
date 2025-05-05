#include<stdio.h>
#define MAX 20
void MergeSort(int Data[],int iLow,int iUp);
void Copy(int Data[],int Temp[],int iLow,int iUp);
void Merge(int Data[],int Temp[],int iLow1,int iUp1,int iLow2,int iUp2);
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
	
	MergeSort(Data,0,iSize-1);
	
	printf("\n-----YOUR SORTED DATA-----\n");
	for(iCounter=0 ; iCounter<iSize ; iCounter++)
		printf("%d\t",Data[iCounter]);
	
	return 0;
}
void MergeSort(int Data[],int iLow,int iUp)
{
	int iMid;
	int Temp[MAX]={0};
	
	if(iLow>=iUp)
		return;
	
	iMid=(iLow+iUp)/2;
	MergeSort(Data,iLow,iMid);
	MergeSort(Data,iMid+1,iUp);
	Merge(Data,Temp,iLow,iMid,iMid+1,iUp);
	Copy(Data,Temp,iLow,iUp);
}
void Merge(int Data[],int Temp[],int iLow1,int iUp1,int iLow2,int iUp2)
{
	int iCounter=iLow1;
	
	while(iLow1<=iUp1 && iLow2<=iUp2)
	{
		if(Data[iLow1]<Data[iLow2])
			Temp[iCounter++]=Data[iLow1++];
		else
			Temp[iCounter++]=Data[iLow2++];
	}
	
	while(iLow1<=iUp1)
		Temp[iCounter++]=Data[iLow1++];
	
	while(iLow2<=iUp2)
		Temp[iCounter++]=Data[iLow2++];
}
void Copy(int Data[],int Temp[],int iLow,int iUp)
{	
	while(iLow<=iUp)
	{
		Data[iLow]=Temp[iLow];
		iLow++;
	}
}
