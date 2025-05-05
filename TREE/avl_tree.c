#include<stdio.h>
#include<malloc.h>
#include"queue.h"
#include"avl_tree.h"
void InsertBST(struct Node **ppHead,int iData)
{
	int iFlag;
	struct Node *pTemp=NULL;
	struct Node *pParent=NULL;
	struct Node *pNewNode=NULL;
	
	//AFTER GETTING LOCATION pTemp WILL GOING TO BE NULL SO WE NEED pParent TO POINT OUR DESIRED NODE
	pTemp=*ppHead;
	while(pTemp != NULL)
	{
		pParent=pTemp;
		if(iData < pTemp->iNo)
			pTemp=pTemp->pLeft;
		else if(iData > pTemp->iNo)
			pTemp=pTemp->pLeft;
		else
		{
			printf("DUPLICATE DATA\n\n");
			return;
		}
	}
	
	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL == pNewNode)
	{
		printf("MEMORY ALLOCATION FAILED\n\n");
		return;
	}
	pNewNode->iNo=iData;
	pNewNode->pLeft=pNewNode->pRight=NULL;
	pNewNode->pParent=pParent;
	
	if(NULL == *ppHead)
		*ppHead=pNewNode;
	else if(iData < pParent->iNo)
	{
		pParent->pLeft=pNewNode;
		iFlag=1;							//NEW CHILD ON LEFT SIDE
	}
	else 
	{
		pParent->pRight=pNewNode;
		iFlag=0;							//NEW CHILD ON RIGHT SIDE
	}
	
	BalanceTree(ppHead,pNewNode->pParent,iFlag);
}

void BalanceTree(struct Node **ppHead,struct Node *pTemp,int iFlag)
{
	int iBF;
	
	while(pTemp != NULL)
	{
		iBF=BalanceFactor(pTemp->pParent);
		printf("BALANCE FACTOR OF %d=%d\n",pTemp->pParent->iNo,iBF);
		
		// if(2 == iBF)
		// {
			// if(1 == iFlag)
				// RightRotation(ppHead,&pTemp);
			// else
				// LeftRightRotation();
			// break;
		// }
		// else if(-2 == iBF)
		// {
			// if(1 == iFlag)
				// LeftRotation();
			// else
				// RightLeftRotation();
			// break;
		// }
		
		pTemp=pTemp->pParent;
	}
}
int BalanceFactor(struct Node *pHead)
{
	return (Height(pHead->pLeft)-Height(pHead->pRight));
}
// void BalanceTree(struct Node **ppHead,struct Node **ppNode,int iFlag)
// {
	// int iTest;
	// int iBF;
	// struct Node **ppTemp;
	// ppTemp=ppNode;
	
	// while(*ppTemp != NULL)
	// {
		// iBF=BalanceFactor(*ppTemp);
		// printf("Balance Factor %d = %d\n",(*ppTemp)->iNo,iBF);
		
		// if(2 == iBF)
		// {
			// if(1 == iFlag)
				// RightRotation(ppHead,&(*ppTemp));
			// else
				// LeftRightRotation();
			// break;
		//}
		// else if(-2 == iBF)
		// {
			// if(1 == iFlag)
				// LeftRotation();
			// else
				// RightLeftRotation();
			// break;
		// }
		
		// (*ppTemp)=(*ppTemp)->pParent;
	// }
// }
// void RightRotation(struct Node **ppHead,struct Node **ppTemp)
// {
	// if(NULL == (*ppTemp)->pParent)
	// {
		// *ppHead=(*ppTemp)->pLeft;
		// (*ppHead)->pParent=NULL;
		
		// if((*ppHead)->pRight != NULL)
		// {
			// (*ppTemp)->pLeft=(*ppHead)->pRight;
			// (*ppTemp)->pLeft->pParent=*ppTemp;
		// }
		// else
			// (*ppTemp)->pLeft=NULL;
		
		// (*ppHead)->pRight=*ppTemp;
		// (*ppTemp)->pParent=*ppHead;
	// }
	// else if(*ppTemp == (*ppTemp)->pParent->pLeft)
	// {
	
	// }
	// else
	// {
	
	// }
// }

// void BalanceTree(struct Node **ppHead,struct Node **ppHead1,int iFlag)
// {
	// int iBF;
	// struct Node *pTemp=*ppHead;
	// pTemp=*ppHead;
	// while(pTemp!=NULL)
	// {
		// iBF=Height((pTemp)->pLeft)-Height((pTemp)->pRight);
		// if(iBF==2)
		// {
			// if(iFlag==1)
				// RightRotation(&pTemp,ppHead1);
			// else
				// LeftRightRotation(&pTemp,ppHead1);
			// break;
		// }
		// else if(iBF==-2)
		// {
			// if(1==iFlag)
				// RightLeftRotation(&pTemp,ppHead1);
			// else
				// LeftRotation(&pTemp,ppHead1);
			// break;
		// }
		// pTemp=pTemp->pParent;
	// }
// }
// void RightRotation(struct Node **ppHead,struct Node **ppHead1)
// {
	// if(NULL == (*ppHead)->pParent)
	// {
		// *ppHead1=(*ppHead)->pLeft;
		// (*ppHead)->pLeft->pParent=NULL;
		
		// (*ppHead)->pParent=(*ppHead)->pLeft;
		
		// if((*ppHead)->pLeft->pRight != NULL)
		// {
			// (*ppHead)->pLeft=(*ppHead)->pLeft->pRight;
			// (*ppHead)->pLeft->pParent=*ppHead;
		// }
		// else
			// (*ppHead)->pLeft=NULL;
			
		// (*ppHead)->pParent->pRight=*ppHead;
		// return;
	// }
	
	// if((*ppHead)->pParent->pLeft==*ppHead)
	// {
		// (*ppHead)->pParent->pLeft=(*ppHead)->pLeft;
		// (*ppHead)->pLeft->pParent=(*ppHead)->pParent;
		// if((*ppHead)->pLeft->pRight!=NULL)
		// {
			// (*ppHead)->pLeft=(*ppHead)->pLeft->pRight;
			// (*ppHead)->pLeft->pParent=*ppHead;
		// }
		// (*ppHead)->pParent->pLeft->pRight=*ppHead;
		// (*ppHead)->pParent=(*ppHead)->pParent->pLeft;
	// }
	// else
	// {
		// (*ppHead)->pParent->pRight=(*ppHead)->pLeft;
		// (*ppHead)->pLeft->pParent=(*ppHead)->pParent;
		// if((*ppHead)->pLeft->pRight!=NULL)
		// {
			// (*ppHead)->pLeft=(*ppHead)->pLeft->pRight;
			// (*ppHead)->pLeft->pParent=*ppHead;
		// }
		// (*ppHead)->pParent->pRight->pRight=*ppHead;
		// (*ppHead)->pParent=(*ppHead)->pParent->pRight;
	// }
// }
// void LeftRotation(struct Node **ppHead,struct Node **ppHead1)
// {
	// if(NULL == (*ppHead)->pParent)
	// {
		// *ppHead1=(*ppHead)->pRight;
		// (*ppHead)->pRight->pParent=NULL;
		
		// (*ppHead)->pParent=(*ppHead)->pRight;
		
		// if((*ppHead)->pParent->pLeft != NULL)
		// {
			// (*ppHead)->pRight=(*ppHead)->pParent->pLeft;
			// (*ppHead)->pRight->pParent=*ppHead;
		// }
		// else
			// (*ppHead)->pRight=NULL;
			
		// (*ppHead)->pParent->pLeft=*ppHead;
		// return;
	// }
	// if((*ppHead)->pParent->pLeft==*ppHead)
	// {
		// (*ppHead)->pParent->pLeft=(*ppHead)->pRight;
		// (*ppHead)->pRight->pParent=(*ppHead)->pParent;
		// if((*ppHead)->pRight->pLeft!=NULL)
		// {
			// (*ppHead)->pRight=(*ppHead)->pRight->pLeft;
			// (*ppHead)->pRight->pParent=*ppHead;
		// }
		// (*ppHead)->pParent->pLeft->pLeft=*ppHead;
		// (*ppHead)->pParent=(*ppHead)->pParent->pLeft;
	// }
	// else
	// {
		// (*ppHead)->pParent->pRight=(*ppHead)->pRight;
		// (*ppHead)->pRight->pParent=(*ppHead)->pParent;
		// if((*ppHead)->pRight->pLeft!=NULL)
		// {
			// (*ppHead)->pRight=(*ppHead)->pRight->pLeft;
			// (*ppHead)->pRight->pParent=*ppHead;
		// }
		// (*ppHead)->pParent->pRight->pLeft=*ppHead;
		// (*ppHead)->pParent=(*ppHead)->pParent->pRight;
	// }

// }void LeftRightRotation(struct Node **ppHead,struct Node **ppHead1)
// {
	// LeftRotation(&((*ppHead)->pLeft),ppHead1);
	// RightRotation(ppHead,ppHead1);
// }
// void RightLeftRotation(struct Node **ppHead,struct Node **ppHead1)
// {
	// RightRotation(&((*ppHead)->pRight),ppHead1);
	// LeftRightRotation(ppHead,ppHead1);
// }
int Height(struct Node *pHead)
{
	int iLeftHeight;
	int iRightHeight;

	if(NULL==pHead)
		return 0;

	iLeftHeight=Height(pHead->pLeft);
	iRightHeight=Height(pHead->pRight);

	if(iLeftHeight>iRightHeight)
		return (iLeftHeight+1);
	else
		return (iRightHeight+1);
}
void InOrder(struct Node *pHead)
{
	if(NULL==pHead)
		return;
	
	PreOrder(pHead->pLeft);
	printf("%d\t",pHead->iNo);
	PreOrder(pHead->pRight);
}
void PreOrder(struct Node *pHead)
{
	if(NULL==pHead)
		return;
	
	printf("%d\t",pHead->iNo);
	PreOrder(pHead->pLeft);
	PreOrder(pHead->pRight);
}
void PostOrder(struct Node *pHead)
{
	if(NULL==pHead)
		return;
	
	PostOrder(pHead->pLeft);
	PostOrder(pHead->pRight);
	printf("%d\t",pHead->iNo);
}
void LevelOrder(struct Node *pHead)
{
	struct Queue *pQueue=NULL;
	struct Node *pTemp=NULL;
	
	EnQueue(&pQueue,pHead);
	while((pTemp=DeQueue(&pQueue))!=NULL)
	{
		printf("%d\t",pTemp->iNo);
		if(pTemp->pLeft!=NULL)
			EnQueue(&pQueue,pTemp->pLeft);
		else if(pTemp->pRight!=NULL)
			EnQueue(&pQueue,pTemp->pRight);
	}
	printf("\n\n");
}
int CountNodes(struct Node *pHead)
{
	static int iCount=0;
	
	if(NULL == pHead)
		return 0;
	
	iCount++;
	
	CountNodes(pHead->pLeft);
	CountNodes(pHead->pRight);
	
	return iCount;
}
int LeafNodeCount(struct Node *pHead)
{
	static int iCount=0;
	
	if(NULL == pHead)
		return 0;
	
	if(NULL == pHead->pLeft && NULL == pHead->pRight)
		iCount++;
	
	LeafNodeCount(pHead->pLeft);
	LeafNodeCount(pHead->pRight);
	
	return iCount;
}
int NonLeafNodeCount(struct Node *pHead)
{
	static int iCount=0;
	
	if(NULL == pHead)
		return 0;

	if(pHead->pLeft != NULL || pHead->pRight != NULL)
		iCount++;
	
	CountNodes(pHead->pLeft);
	CountNodes(pHead->pRight);
	
	return iCount;
}
struct Node * SearchNonRecursive(struct Node *pHead,int iKey)
{
	while(pHead != NULL)
	{
		if(iKey < pHead->iNo)
			pHead=pHead->pLeft;
		else if (iKey > pHead->iNo)
			pHead=pHead->pRight;
		else
			break;
	}
	return pHead;
}
struct Node * SearchRecursive(struct Node *pHead,int iKey)
{
	while(pHead != NULL)
	{
		if(iKey < pHead->iNo)
			return SearchRecursive(pHead->pLeft,iKey);
		else if(iKey > pHead->iNo)
			return SearchRecursive(pHead->pRight,iKey);
		else
			break;
	}
	return pHead;
}
void DeleteNode(struct Node **ppHead,int iData)
{
	struct Node *pTemp=NULL;
	struct Node *pChild=NULL;
	struct Node *pParent=NULL;
	struct Node *pSuccessor=NULL;
	
	if(NULL==*ppHead)
		return;
	
	pTemp=*ppHead;
	while(pTemp != NULL)
	{
		if(iData==pTemp->iNo)
			break;
		
		pParent=pTemp;
		if(iData < pTemp->iNo)
			pTemp=pTemp->pLeft;
		else
			pTemp=pTemp->pRight;
	}
	
	if(pTemp->pLeft != NULL && pTemp->pRight != NULL)
	{
		pParent=pTemp;
		pSuccessor=pTemp->pRight;
		
		while(pSuccessor->pLeft!=NULL)
		{
			pParent=pSuccessor;
			pSuccessor=pSuccessor->pLeft;
		}
		pTemp->iNo=pSuccessor->iNo;
		pTemp=pSuccessor;
	}
	
	if(pTemp->pLeft!=NULL)
		pChild=pTemp->pLeft;
	else
		pChild=pTemp->pRight;
	
	if(NULL == pParent)
		*ppHead=NULL;
	else if(pTemp == pParent->pLeft)
		pParent->pLeft=pChild;
	else
		pParent->pRight=pChild;
	
	free(pTemp);
	
	pTemp=NULL;
	pChild=NULL;
	pSuccessor=NULL;
}
void DeleteAll(struct Node **ppHead)
{
	if(NULL==*ppHead)
		return;
	
	DeleteAll(&((*ppHead)->pLeft));
	DeleteAll(&((*ppHead)->pRight));
	
	free(*ppHead);
	*ppHead=NULL;
}
