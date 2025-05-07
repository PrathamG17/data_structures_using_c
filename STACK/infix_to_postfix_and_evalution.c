#include<stdio.h>
#include<math.h>
#include"stack.h"
#define MAX 50

int IsSpace(char ChSymbol);
int IsOperator(char ChSymbol);
int PostfixEvaluation(const char *pszPostfix);
int PostfixEvaluation(const char *pszPostfix);
void InfixToPostfix(const char *pszInfix,char *pszPostfix);

int main(void)
{
	int iResult;
	char szInfix[MAX]={0};
	char szPostfix[MAX]={0};
	char Stack[MAX]={0};
	
	printf("ENTER YOUR EXPRESSION:\t");
	gets(szInfix);
	
	InfixToPostfix(szInfix,szPostfix);
	puts(szPostfix);
	
	iResult=PostfixEvaluation(szPostfix);
	
	printf("RESULT=%d\n\n",iResult);
	
	return 0;
}
void InfixToPostfix(const char *pszInfix,char *pszPostfix)
{
	int iCounter1=0;
	int iCounter2=0;
	char ChSymbol;
	int iPrecedence;
	
	extern int g_iTop;
	extern long int g_Stack[STACK_MAX];
	
	for(iCounter1=0;pszInfix[iCounter1]!='\0';iCounter1++)
	{
		ChSymbol=pszInfix[iCounter1];
		if(IsSpace(ChSymbol))
			continue;
		if((iPrecedence=IsOperator(ChSymbol))!=0)
		{
			while((!IsEmpty()) && (IsOperator(g_Stack[g_iTop]) >= iPrecedence))
				pszPostfix[iCounter2++]=Pop();
			Push(ChSymbol);
		}
		else
		{	
			if(ChSymbol=='(')
				Push(ChSymbol);
			else if(ChSymbol==')')
			{
				
				while(1)
				{
					ChSymbol=Pop();
					if(ChSymbol=='(')
						break;
					pszPostfix[iCounter2++]=ChSymbol;
				}
			}
			else
			{
				pszPostfix[iCounter2++]='[';
				pszPostfix[iCounter2++]=ChSymbol;
				while(1)
				{
					ChSymbol=pszInfix[++iCounter1];
					if(IsSpace(ChSymbol))
						continue;
					if(IsOperator(ChSymbol) || ChSymbol=='\0' || ChSymbol==')')
					{
						pszPostfix[iCounter2++]=']';
						break;
					}
					pszPostfix[iCounter2++]=ChSymbol;
				}
				iCounter1--;
			}
		}
	}
	while(!IsEmpty())
		pszPostfix[iCounter2++]=Pop();

	pszPostfix[iCounter2]='\0';
}
int IsSpace(char ChSymbol)
{
	if(' '==ChSymbol || '\t'==ChSymbol)
		return 1;
	return 0;
}
int IsOperator(char ChSymbol)
{
	switch(ChSymbol)
	{
		case '+':
		case '-': return 1;
		
		case '*':
		case '/':
		case '%': return 2;
		
		case '^': return 3;
		
		default : return 0;
	}
}
int PostfixEvaluation(const char *pszPostfix)
{
	int iCounter1;
	int iOperand1;
	int iOperand2;
	char ChSymbol;
	int iResult;
	char szTemp[STACK_MAX]={0};
	
	for(iCounter1=0;pszPostfix[iCounter1]!=0;iCounter1++)		
	{
		ChSymbol=pszPostfix[iCounter1];
		if(IsOperator(ChSymbol))
		{
			switch(ChSymbol)
			{
				case '+': iOperand2=Pop();
						  iOperand1=Pop();
						  iResult=iOperand1+iOperand2;
						  Push(iResult);
						  break;
				case '-': iOperand2=Pop();
						  iOperand1=Pop();
						  Push(iOperand1-iOperand2);
						  break;
				case '*': iOperand2=Pop();
						  iOperand1=Pop();
						  Push(iOperand1*iOperand2);
						  break;
				case '/': iOperand2=Pop();
						  iOperand1=Pop();
						  Push(iOperand1/iOperand2);
						  break;
				case '%': iOperand2=Pop();
						  iOperand1=Pop();
						  Push(iOperand1%iOperand2);
						  break;
				case '^': iOperand2=Pop();
						  iOperand1=Pop();
						  Push(pow(iOperand1,iOperand2));
						  break;
			}
		}
		else
		{
			if(ChSymbol=='[')
			{
				int iCounter2=0;
				while(1)
				{
					ChSymbol=pszPostfix[++iCounter1];    
					if(ChSymbol==']')
						break;
					szTemp[iCounter2++]=ChSymbol;
				}
				szTemp[iCounter2]='\0';
				Push(atoi(szTemp));
			}
		}
	}
	return Pop();
}