#include<stdio.h>
#define MAX 10
int main(void)
{
	int iTemp;
	int iSize;
	int iCounter1;
	int iCounter2;
	int iCounter3;
	int iAdjCount;
	int Data[MAX]={0};
	int AdjMatrix[MAX][MAX]={0};
	
	printf("-->ENTER NUMBER OF VERTICES(<10):  ");
	scanf("%d",&iSize);
	
	for(iCounter1=0 ; iCounter1 < iSize ; iCounter1++)
	{
		printf("\n\tENTER VERTEX %d = ",iCounter1+1);
		scanf("%d",&Data[iCounter1]);
	}
	
	for(iCounter1=0 ; iCounter1 < iSize ; iCounter1++)
	{
		printf("\n-->HOW MANY ADJACENT VERTICES FOR %d:  ",Data[iCounter1]);
		scanf("%d",&iAdjCount);
		for(iCounter2=0 ; iCounter2 < iAdjCount ; iCounter2++)
		{
			printf("\n\tENTER ADJACENT VERTEX %d = ",iCounter2+1);
			scanf("%d",&iTemp);
			
			for(iCounter3=0 ; iCounter3 < iSize ; iCounter3++)
			{
				if(iTemp == Data[iCounter3])
					break;
			}
			AdjMatrix[iCounter1][iCounter3]=1;
		}
	}
	
	printf("\nGRPAH IS....");
	for(iCounter1=0 ; iCounter1 < iSize ; iCounter1++)
	{
		printf("\n%d=  ",Data[iCounter1]);
		for(iCounter2=0 ; iCounter2 < iSize ; iCounter2++)
		{
			if(AdjMatrix[iCounter1][iCounter2] != 0)
				printf("-->>%d",Data[iCounter2]);
		}
	}
	
	return 0;
}
