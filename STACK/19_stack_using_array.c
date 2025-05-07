#include<stdio.h>
#define MAX 5
int IsFull(void);
int IsEmpty(void);
int Pop(int *pStack);
void Display(const int *pStack);
void Push(int *pStack,int iData);
int g_iTop= -1;
int main(void)
{
	int Stack[MAX]={0};
	int iPoppedData;
	
	Display(Stack);
	
	Push(Stack,50);
	Push(Stack,40);
	Push(Stack,30);
	Push(Stack,20);
	Push(Stack,10);
	
	printf("------AFTER PUSH------\n\n");
	Display(Stack);

	iPoppedData=Pop(Stack);
	if(iPoppedData != -1)
		printf("\n%d IS DELETED\n\n",iPoppedData);
	else
		printf("\nSTACK IS EMPTY\n\n");
	
	printf("------AFTER POP------\n\n");
	Display(Stack);

	return 0;
}
void Push(int *pStack,int iData)
{
		if(IsFull())
		{
			printf("\nSTACK OVERFLOW\n\n");
			return;
		}
		pStack[++g_iTop]=iData;
}
int Pop(int *pStack)
{
	if(IsEmpty())
	{
		printf("\nSTACK IS EMPTY\n\n");
		return -1;
	}
	return pStack[g_iTop--];
}
int IsFull(void)
{
	if(g_iTop==MAX-1)
		return 1;
	return 0;
}
int IsEmpty(void)
{
	if(-1==g_iTop)
		return 1;
	return 0;
}
void Display(const int *pStack)
{
	int iCounter;
	if(-1==g_iTop)
	{
		printf("\nSTACK IS EMPTY\n\n");
		return;
	}
	for(iCounter=g_iTop;iCounter>=0;iCounter--)
		printf("\t%d\n",pStack[iCounter]);
}
