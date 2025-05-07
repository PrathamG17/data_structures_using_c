#include<stdio.h>
#include<math.h>
#define MAX 50
#define STACK_MAX 15

int Pop(void);
int IsFull(void);
int IsEmpty(void);
void Push(long lSymbol);

int IsSpace(char chSymbol);
int IsOperator(char chSymbol);
long PostfixEvaluation(const char *pszPostfix);			   //const-NEVER CHANGE pszPostfix ONLY EVALUATE
void InfixToPostfix(const char *pszInfix,char *pszPostfix); //const-NEVER CHANGE pszInfix ONLY CONVERT

int g_iTop=-1;	
long int g_Stack[STACK_MAX]={0};		

int main(void)
{
	long lResult;
	char szInfix[MAX]={0};
	char szPostfix[MAX]={0};
	
	printf("ENTER YOUR EXPRESSION:-");
	gets(szInfix);											//IN CASE OF SPACE scanf() INCONVINIENT
	
	InfixToPostfix(szInfix,szPostfix);
	puts(szPostfix);
	
	lResult=PostfixEvaluation(szPostfix);
	printf("ANSWER:-%d\n\n",lResult);
	
	return 0;
}
void InfixToPostfix(const char *pszInfix,char *pszPostfix)
{
	int iCounter1;
	int iCounter2=0;
	int iPrecedence;
	char chSymbol;
	
	//extern long int g_Stack[STACK_MAX];		//FOR USE IN MORE THAN ONE FILE-extern
	//extern int g_iTop;
	
	for(iCounter1=0;pszInfix[iCounter1]!='\0';iCounter1++)
	{
		chSymbol=pszInfix[iCounter1];
		
		if(IsSpace(chSymbol))
			continue;
		
		if((iPrecedence=IsOperator(chSymbol)) != 0) 	//SURELY chSymbol WILL BE OPERATOR
		{
			while(!IsEmpty() && IsOperator(g_Stack[g_iTop]) >= iPrecedence)
				pszPostfix[iCounter2++]=Pop();
			Push(chSymbol);
		}
		else 				// SURELY chSymbol WILL BE '(' OR ')' OR NORMAL OPERAND
		{
			if('('==chSymbol)
				Push(chSymbol);
			else if(')'==chSymbol)
			{
				while(1)
				{
					chSymbol=Pop();
					if('('==chSymbol)
						break;
					pszPostfix[iCounter2++]=chSymbol;
				}
			}
			else						//SURELY NORMAL OPERAND
			{
				pszPostfix[iCounter2++]='[';
				pszPostfix[iCounter2++]=chSymbol;
				while(1)
				{
					chSymbol=pszInfix[++iCounter1];

					if(IsSpace(chSymbol))
						continue;
					
					if(IsOperator(chSymbol) || chSymbol=='\0' || chSymbol==')')
					{
						pszPostfix[iCounter2++]=']';
						break;
					}
					pszPostfix[iCounter2++]=chSymbol;
				}
				iCounter1--;			// MANDATORY TO COME ONE STEP BACK FOR 'OPERATOR','\0',')'
			}
		}
	}
	while(!IsEmpty())
		pszPostfix[iCounter2++]=Pop();	
	
	pszPostfix[iCounter2]='\0';			//POSTFIX EXPRESSION IS READY SO string COMPLETED 
}
int IsSpace(char chSymbol)
{
	if(' '==chSymbol || '\t'==chSymbol)
		return 1;
	return 0;
}
int IsOperator(char chSymbol)
{
	switch(chSymbol)
	{
		case '+':
		case '-':	return 1;
		
		case '*':
		case '/':
		case '%':	return 2;
		
		case '^':	return 3;
		
		default :	return 0;
	}
}
long PostfixEvaluation(const char *pszPostfix)
{
	int iCounter1;
	int iOperand1;
	int iOperand2;
	char chSymbol;
	char szTemp[STACK_MAX]={0};
	int iCounter2;
	for(iCounter1=0;pszPostfix[iCounter1]!='\0';iCounter1++)
	{
		chSymbol=pszPostfix[iCounter1];
		
		if('['==chSymbol)
		{
			iCounter2=0;
			while(1)
			{
				chSymbol=pszPostfix[++iCounter1];
				if(']'==chSymbol)
					break;
				szTemp[iCounter2++]=chSymbol;
			}
			szTemp[iCounter2]='\0';		//szTemp WORK DONE 
			Push(atoi(szTemp));
		}
		else
		{
			iOperand2=Pop();			//IT WILL Pop() ENTIRE OBJECT DUE TO atoi()
			iOperand1=Pop();
			switch(chSymbol)
			{
				case '+':	Push(iOperand1+iOperand2);
							break;
							
				case '-':	Push(iOperand1-iOperand2);
							break;
							
				case '*':	Push(iOperand1*iOperand2);
							break;
							
				case '/':	Push(iOperand1/iOperand2);
							break;
							
				case '%':	Push(iOperand1%iOperand2);
							break;
							
				case '^':	Push(pow(iOperand1,iOperand2));
							break;
			}
		}
		
	}
	return Pop();
}

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
