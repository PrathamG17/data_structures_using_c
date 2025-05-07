#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void counting_sort(int array[],int size)
{
	int output[MAX];
    int count[MAX];
    int max = array[0],i;

    // Here we find the largest item in the array
    for (i = 1; i < size; i++) { if (array[i] > max)
            max = array[i];
    }

    // Initialize the count for each element in array to 0
    for ( i = 0; i <= max; ++i)
	{
        count[i] = 0;
    }

    // For each element we store the count
    for ( i = 0; i < size; i++)
	{
        count[array[i]]++;
    }

    // Store the cummulative count of each array
    for ( i = 1; i <= max; i++)
	{
		count[i] += count[i - 1];
	}
	
	// Search the index of each element of the actual array in count array, and
	// place the elements in output array
	for ( i = size - 1; i >= 0; i--) 
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Transfer the sorted items into actual array
    for (i = 0; i < size; i++)
	{
        array[i] = output[i];
    }
}
void generate(int A[50],int n)
{
	int i;
for(i=0;i<n;i++)
{
A[i]=rand()%100;
}
}
int main()
{
int n,k=0,A[15],i;
printf("Enter The Number:");
scanf("%d",&n);
generate(A,n);
for(i=1;i<=n;i++)
printf("%d\n",A[i]);
for(i=1;i<=n;i++)
{
if(A[i]>k)
{
k=A[i];
}
}
counting_sort(A,n);
printf("\n");
return 0;
}
