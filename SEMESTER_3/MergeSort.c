#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void Merge(int Arr1[],int Low,int High,int Mid);
void MergeSort(int Arr1[],int Low,int High);
void CreateArray(int Arr1[],int Size1);
void Display(int Arr1[],int Size1);
int main()
{
    int Arr[MAX],Size;
	printf("\nPLEASE ENTER HOW MANY ELEMENTS YOU WANT TO ENTER:\t");
	scanf("%d",&Size);
    CreateArray(Arr,Size);
    printf("\nYOUR ARRAY\n\n");
    Display(Arr,Size);
    MergeSort(Arr,0,Size-1);
    printf("\n\nYOUR SORTED ARRAY\n\n");
    Display(Arr,Size);
    return 0;
}
void Merge(int Arr1[],int Low,int High,int Mid)
{
    int i,j,k;
    i=Low,j=Mid+1,k=0;
    int B[MAX];
    while(i<=Mid && j<=High)
	{
        if(Arr1[i]<Arr1[j])
		{
            B[k]=Arr1[i];
            k++,i++;
        }
        else
		{
            B[k]=Arr1[j];
            j++,k++;
        }
    }
    while(i<=Mid)
	{
        B[k]=Arr1[i];
        k++;i++;
    }
    while(j<=High)
	{
        B[k]=Arr1[j];
        k++;j++;
    }
    for(k=0,i=Low;i<=High;i++,k++)
        Arr1[i]=B[k];
}
void MergeSort(int Arr1[],int Low,int High)
{
    if(Low<High)
	{
        int Mid=(Low+High)/2;
        MergeSort(Arr1,Low,Mid);
        MergeSort(Arr1,Mid+1,High);
        Merge(Arr1,Low,High,Mid);
    }
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
