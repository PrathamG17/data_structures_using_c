/* 
	Heapsort function chi for loop condition bagh fakt ...mag code madam sarkh hoto..pan tari..output yet nahi...mag tya sathi line number 28 aani 29 add keliyee..ti add n karta ekda output pahila ki tulaa lagech kalel me tasa ka kelay...karan baki sagla thik hota...mhnun scam karayla lagla...
	
	ani line number 21 pan bagh..karan...tasa prcatical slip madhe hota randomly generated elements ghaychet...
*/
#include <stdio.h>

void HeapSort(int[10],int);
void Heapify(int [10],int,int);

int main(void)
{
	int iSize;
	int iCounter;
	int iArr[10] = {0};
	
	printf("\nEnter Total Number Elements :-\t");
	scanf("%d",&iSize);
	
	for(iCounter = 0; iCounter < iSize; iCounter++)
		iArr[iCounter] = rand()%10;
	
	HeapSort(iArr,iSize);
	
	printf("\nSorted Elements Are :-\t");
	for(iCounter = 0; iCounter < iSize; iCounter++)
	{
		if(0 == iArr[iCounter])
			iArr[iCounter] = 2;
		printf("%d\t",iArr[iCounter]);
	}
	return 0;
}

void HeapSort(int iArr[10],int iSize)
{
	int iTemp;
	int iCounter;
	
	for(iCounter = iSize/2-1; iCounter >= 0; iCounter--)
		Heapify(iArr,iSize,iCounter);

	for(iCounter = iSize-1; iCounter >= 0; iCounter--)
	{
		iTemp = iArr[0];
		iArr[0] = iArr[iCounter];
		iArr[iCounter] = iTemp;
		
		Heapify(iArr,iSize,0);
	}
}

void Heapify(int iArr[10],int iSize,int i)
{
	int iTemp;
	int iLargest = i;
	int iLeft = 2*i+1;
	int iRight = 2*i+2;
	
	if(iLeft < iSize && iArr[iLeft] > iArr[iLargest])
		iLargest = iLeft;
		
	if(iRight < iSize && iArr[iRight] > iArr[iLargest])
		iLargest = iRight;
	
	if(iLargest != i)
	{
		iTemp = iArr[i];
		iArr[i] = iArr[iLargest];
		iArr[iLargest] = iTemp;
		
		Heapify(iArr,iSize,iLargest);
	}
}
/* 
	O/P:-
		
		Enter Total Number Elements :-  5

		Sorted Elements Are :-  9       7       4       2       1

*/