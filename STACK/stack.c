#include<stdio.h>
#include"stack.h"
long int g_Stack[STACK_MAX]={0};		
int g_iTop=-1;	
void Push(long lSymbol)					//STACK PUSH  ASCII VALUE OF lSymbol
{
	if(IsFull())
	{
		printf("STACK OVERFLOW\n\n");
		return;
	}
	g_Stack[++g_iTop]=lSymbol;
}
int Pop(void)
{
	if(IsEmpty())
	{
		printf("STACK EMPTY\n\n");
		return -1;
	}
	 return g_Stack[g_iTop--];
}
int IsFull(void)
{
	if(g_iTop==STACK_MAX-1)
		return 1;
	return 0;
}
int IsEmpty(void)
{
	if(g_iTop==-1)
		return 1;
	return 0;
}
