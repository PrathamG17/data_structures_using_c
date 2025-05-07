#include<stdio.h>
#include<stdlib.h>
int iStack[20],iTop=-1;
#include"Stack.h"
int main(void)
{
	int iChoice,iNo,iCounter,iCheck;
	while(1)
	{
		printf("\n----------MENU----------\n");
		printf("1.Push(INSERT ELEMENT AT TOP)\n2.Pop(REMOVE TOP ELEMENT)\n3.Peek(GIVE TOP ELEMENT)\n4.Display(SHOW ALL STACK ELEMENT)\n5.Exit\n");
		printf("\nPLEASE ENTER YOUR CHOICE:\t");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1: iCheck=IsFull();
					if(0==iCheck)
					{
						printf("\nPLEASE ENTER THE ELEMENT YOU WANT TO INSERT INTO STACK:\t");
						scanf("%d",&iNo);
						Push(iNo);
					}
					else if(1==iCheck)
						printf("\nSTACK OVERFLOW\n");
					break;
			case 2: iCheck=IsEmpty();
					if(0==iCheck)
					{
						iNo=Pop();
						printf("\nDELETED ELEMENT IS %d\n",iNo);
					}
					else if(1==iCheck)
						printf("\nSTACK UNDERFLOW\n");
					break;
			case 3: iCheck=IsEmpty();
					if(0==iCheck)
					{
						iNo=Peek();
						printf("\nTOP ELEMENT IS %d\n",iNo);
					}
					else if(1==iCheck)
						printf("\nSTACK UNDERFLOW\n");
					break;
			case 4: iCheck=IsEmpty();
					if(0==iCheck)
					{
						for(iCounter=0;iCounter<=iTop;iCounter++)
							printf("\nELEMENT NO. %d:\t%d\n",iCounter+1,iStack[iCounter]);
					}
					else if(1==iCheck)
						printf("\nSTACK UNDERFLOW");
					break;
			case 5: exit(1);
		}
	}
}