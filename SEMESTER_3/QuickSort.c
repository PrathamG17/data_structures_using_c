#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void QuickSort(int[],int,int);
int Partition(int[],int,int);
void Swap(int *,int *);
void CreateArray(int[],int);
void Display(int[],int);
int main()
{
    int Arr[MAX],Size;
    printf("\nPLEASE ENTER HOW MANY ELEMENTS YOU WANT TO ENTER:\t");
	scanf("%d",&Size);
    CreateArray(Arr,Size);
    Display(Arr,Size);
    QuickSort(Arr,0,Size- 1);
	printf("\n\nYOUR SORTED ARRAY\n\n");
    Display(Arr,Size);
    return 0;
}
void QuickSort(int Arr1[],int Low,int High)
{
    int P;
    if(Low<High)
    {
        P=Partition(Arr1,Low,High);
        QuickSort(Arr1,Low,P-1);
        QuickSort(Arr1,P+1,High);
    }
}
int Partition(int Arr1[],int Low,int High)
{
    int Pivot=Arr1[Low],i=Low+1,j=High;
    do
    {
        while (Arr1[i] <= Pivot)
            i++;
        while (Arr1[j] > Pivot)
            j--;
        if (i < j)
            Swap(&Arr1[i], &Arr1[j]);
    } while(i<j);
    Swap(&Arr1[Low], &Arr1[j]);
    return j;
}
void Swap(int *Ptr1, int *Ptr2)
{
    int Temp; 
	Temp=*Ptr1;
    *Ptr1=*Ptr2;
    *Ptr2=Temp;
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