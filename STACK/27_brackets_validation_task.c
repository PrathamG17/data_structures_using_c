#include<stdio.h>
#define MAX 25
#define STACK_MAX 10

int IsFull(void);
int IsEmpty(void);
int Pop(char *pStack);
void Push(char *pStack,int iData);
void CheckBrackets(char *pExpression,char *pStack);

int g_iTop=-1;

int main(void)
{
	char Expression[MAX]={0};
	char Stack[STACK_MAX]={0};
	
	printf("ENTER YOUR EXPRESSION:\t");
	gets(Expression);
	
	CheckBrackets(Expression,Stack);
	
	return 0;
}
int IsFull(void)
{
	if(MAX-1==g_iTop)
		return 1;
	return 0;
}
int IsEmpty(void)
{
	if(-1==g_iTop)
		return 1;
	return 0;
}
int Pop(char *pStack)
{
	if(IsEmpty())
		return -1;
	return pStack[g_iTop--];
}
void Push(char *pStack,int iData)
{
	if(IsFull())
		return;
	pStack[++g_iTop]=iData;
}
void CheckBrackets(char *pExpression,char *pStack)
{
	int iCounter;
	char chSymbol;
	for(iCounter=0;pExpression[iCounter]!='\0';iCounter++)
	{
		chSymbol=pExpression[iCounter];
		if('('==chSymbol || '['==chSymbol || '{'==chSymbol)
			Push(pStack,chSymbol);
		if(')'==chSymbol)
		{
			if(Pop(pStack)!='(')
				break;
		}
		else if(']'==chSymbol)
		{
			if(Pop(pStack)!='[')
				break;
		}
		else if('}'==chSymbol)
		{
			if(Pop(pStack)!='{')
				break;
		}
	}
	if(IsEmpty() && pExpression[iCounter]=='\0')
		printf("BRACKETS ARE VALID\n\n");
	else
		printf("BRACKETS ARE INVALID\n\n");
}
