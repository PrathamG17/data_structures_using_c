#include<stdio.h>
#include<malloc.h>
#include"tree.h"
#include"queue.h"	//level order traversal
void InsertBST(struct Node **ppHead,int iData)
{
	struct Node *pNewNode=NULL;
	struct Node *pTemp=NULL;
	struct Node *pParent=NULL;

	pTemp=*ppHead;
	while(pTemp!=NULL)
	{
		pParent=pTemp;
		
		if(iData < pTemp->iNo)
			pTemp=pTemp->pLeft;
		else if(iData > pTemp->iNo)
			pTemp=pTemp->pRight;
		else
		{
			printf("DUPLICATE DATA\n\n");
			return;
		}
	}

	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("MEMORY ALLOCATION FAILED\n\n");
		return;
	}
	
	pNewNode->iNo=iData;
	pNewNode->pLeft=pNewNode->pRight=NULL;
	
	if(NULL==*ppHead)											//---------------------------(1)
		*ppHead=pNewNode;
	else if(iData < pParent->iNo)
		pParent->pLeft=pNewNode;
	else
		pParent->pRight=pNewNode;
}
void InOrder(struct Node *pHead)
{
	if(NULL==pHead)
		return;
	
	InOrder(pHead->pLeft);
	printf("%d\t",pHead->iNo);
	InOrder(pHead->pRight);
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
		if(pTemp->pRight!=NULL)
			EnQueue(&pQueue,pTemp->pRight);
	}
	printf("\n\n");
}
int CountNodes(struct Node *pHead)
{
	static int iCount=0;
	
	if(NULL==pHead)
		return 0;
	
	iCount++;
	CountNodes(pHead->pLeft);
	CountNodes(pHead->pRight);
	
	return iCount;
}
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
int LeafNodeCount(struct Node *pHead)
{
	static int iCount=0;
	
	if(NULL==pHead)
		return 0;
	
	if(NULL==pHead->pLeft && NULL==pHead->pRight)
		iCount++;
	
	LeafNodeCount(pHead->pLeft);
	LeafNodeCount(pHead->pRight);
	
	return iCount;
}
int NonLeafNodeCount(struct Node *pHead)
{
	static int iCount=0;
	
	if(NULL==pHead)
		return 0;
	
	if(pHead->pLeft!=NULL || pHead->pRight!=NULL)
		iCount++;
	
	NonLeafNodeCount(pHead->pLeft);
	NonLeafNodeCount(pHead->pRight);
	
	return iCount;
}
struct Node * SearchNonRecursive(struct Node *pHead,int iKey)
{
	while(pHead!=NULL)
	{
		if(iKey<pHead->iNo)
			pHead=pHead->pLeft;
		else if(iKey>pHead->iNo)
			pHead=pHead->pRight;
		else												//NO NEED OF EXPLICIT CHECKING FOR BREAK
			break;
	}
	return pHead;
}
struct Node * SearchRecursive(struct Node *pHead,int iKey)
{
	while(pHead!=NULL)
	{
		if(iKey<pHead->iNo)
			return SearchRecursive(pHead->pLeft,iKey);
		else if(iKey>pHead->iNo)
			return SearchRecursive(pHead->pRight,iKey);
		else 												//CONTROL CAME IN ELSE MEANS DATA FOUND
			break;
	}
	return pHead;
}
void DeleteNode(struct Node **ppHead,int iData)
{
	struct Node *pChild=NULL;
	struct Node *pParent=NULL;
	struct Node *pTemp=*ppHead;
	struct Node *pSuccessor=NULL;
	
	if(NULL==*ppHead)										//IF TREE IS EMPTY
		return;
	
	while(pTemp != NULL)									//FOR FINDING DATA LOCATION
	{
		if(iData == pTemp->iNo)
			break;
		
		pParent=pTemp;
		if(iData < pTemp->iNo)
			pTemp=pTemp->pLeft;
		else if(iData > pTemp->iNo)
			pTemp=pTemp->pRight;
	}
	
	if(pTemp->pLeft != NULL && pTemp->pRight != NULL)		//IF BOTH CHILD PRESENT
	{
		pParent=pTemp;										//PARENT ASSIGN
		pSuccessor=pTemp->pRight;							//SUCCESSOR ASSIGN TO ONE RIGHT
		
		while(pSuccessor->pLeft != NULL)					//AND THEN COMPLETE LEFT
		{
			pParent=pSuccessor;								//WITH PARENT
			pSuccessor=pSuccessor->pLeft;
		}
		
		pTemp->iNo=pSuccessor->iNo;							//SUCCESSOR COPY TO DESIRED NODE
		pTemp=pSuccessor;									//FORWARDING SUCCESOR NODE FOR DELETE
	}
	
	if(pTemp->pLeft != NULL)								//FIRST SURE ABOUT DELETING NODE HAVE 1 OR 0 CHILD CHCEK WHETHER CHILD ARE PRESENT OR NOT
		pChild=pTemp->pLeft;
	else
		pChild=pTemp->pRight;								//IF NOT PRESENT THEN ALSO AUTOMATICALLY NULL CAME IN CHILD
	
	if(NULL == pParent)										//IF ROOT WILL DELETE
		*ppHead=pChild;
	else if(pParent->pLeft == pTemp)						//CHECK ON WHICH SIDE OF PARENT DELETING NODE PRESENT FOR CHILD ASSIGNMENT
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
	
	DeleteAll(&((*ppHead)->pLeft));					//----------SENDING ADDRESS OF DELETING NODE
	DeleteAll(&((*ppHead)->pRight));				//----------SENDING ADDRESS OF DELETING NODE
	
	free(*ppHead);
	*ppHead=NULL;
}
int SmallestBST(struct Node *pHead)
{
	if(NULL == pHead)
		return -1;
		
	while(pHead->pLeft != NULL)
		pHead=pHead->pLeft;
		
	return (pHead->iNo);
}
int LargestBST(struct Node *pHead)
{
	if(NULL == pHead)
		return -1;
		
	while(pHead->pRight != NULL)
		pHead=pHead->pRight;
		
	return (pHead->iNo);
}
