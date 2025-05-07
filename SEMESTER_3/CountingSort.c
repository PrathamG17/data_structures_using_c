#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void CountSort(int[],int);
int Maximum(int[],int);
void CreateArray(int[],int);
void Display(int[],int);
int main(void)
{
    int Arr[MAX],Size;
    printf("\nPLEASE ENTER HOW MANY ELEMENTS YOU WANT TO ENTER:\t");
	scanf("%d",&Size);
    CreateArray(Arr,Size);
    Display(Arr,Size);
    CountSort(Arr,Size);
    printf("\n\nYOUR SORTED ARRAY\n\n");
    Display(Arr,Size);
    return 0;
}
void CountSort(int Arr1[], int Size1)
{
    int Max = Maximum(Arr1,Size1);
    int Count[Max+1];
    int Output[Max];
    int i,j;
    for(i=0;i<Max+1;i++)
    {
        Count[i] = 0;
    }
    for(i=0;i<Size1;i++)
    {
        Count[Arr1[i]]=Count[Arr1[i]]+1;
    }
    for(i=1;i<=Max;i++)
    {
        Count[i]=Count[i]+Count[i-1];
    }
    for(j=Size1-1;j>=0;j--)
    {
        Output[Count[Arr1[j]]=Count[Arr1[j]]-1]=Arr1[j];
        Count[Arr1[j]]=Count[Arr1[j]]-1;
    }
    for(i=0;i<Size1;i++)
    {
        Arr1[i]=Output[i];
    }
}
int Maximum(int Arr1[],int Size1)
{
    int i;
    int Max = 0;
    for(i=0;i<Size1;i++)
    {
        if(Arr1[i]>Max)
            Max=Arr1[i];
    }
    return Max;
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