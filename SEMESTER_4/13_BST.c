/*  
	yaa madhe fakt 34 aani 35 add kelay...baki slip prammane...jevdhe function pahijet tevdhech thvelet.
*/
#include <stdio.h>
#include <malloc.h>

struct node;

void InOrder(struct node *);
int LeafCount(struct node *);
void PreOrder(struct node *);
int CountNodes(struct node *);
void PostOrder(struct node *);
void InsertBST(struct node **,int);

struct node
{
	int iData;
	struct node *pLeft;
	struct node *pRight;
};

int main(void)
{
	int iCounter;
	int iChoice;
	int iNo;
	struct node *pRoot = NULL;
	
	while(1)
	{
		printf("\n1.Create\n2.Insert\n3.PreOrder\n4.InOrder\n5.PostOrder\n6.Count Nodes\n7.Leaf Count\n8.Exit\n");
		printf("\nEnter Choice :\t");
		scanf("%d",&iChoice);
		
		if(2 == iChoice)
			iChoice = 1;
		
		switch(iChoice)
		{
			case 1:
				printf("\nHow many number of elements you want to insert:\t");
				scanf("%d",&iChoice);
				
				for(iCounter = 0; iCounter < iChoice; iCounter++)
				{
					printf("\nElement %d:\t",iCounter+1);
					scanf("%d",&iNo);
					InsertBST(&pRoot,iNo);
				}
				break;
			
			case 3:
				if(NULL == pRoot)
					printf("\nList is Empty\n");
				else
					PreOrder(pRoot);
				break;
				
			case 4:
				if(NULL == pRoot)
					printf("\nList is Empty\n");
				else
					InOrder(pRoot);
				break;
				
			case 5:
				if(NULL == pRoot)
					printf("\nList is Empty\n");
				else
					PostOrder(pRoot);
				break;
			
			case 6:
				iNo = CountNodes(pRoot);
				printf("\nTotal Nodes = %d\n",iNo);
				break;
			
			case 7:
				iNo = LeafCount(pRoot);
				printf("\nTotal Leaf Nodes = %d\n",iNo);
				break;
				
			case 8:
				return 0;
				
			default:
				printf("\nInvalid Choice\n");
		}
	}
	
	return 0;
}

void InsertBST(struct node **ppRoot,int iData)
{
	struct node *pNewNode = NULL;
	struct node *pTemp = NULL;
	
	pNewNode = (struct node *)malloc(sizeof(struct node));
	if(NULL == pNewNode)
	{
		printf("\nMemory Allocation Failed\n");
		return;
	}
	
	pNewNode->iData = iData;
	pNewNode->pLeft = pNewNode->pRight = NULL;
	
	if(NULL == *ppRoot)
		*ppRoot = pNewNode;
	else
	{
		pTemp = *ppRoot;
		while(pTemp != NULL)
		{
			if(pNewNode->iData > pTemp->iData)
			{
				if(NULL == pTemp->pRight)
				{
					pTemp->pRight = pNewNode;
					break;
				}
				else
					pTemp = pTemp->pRight;
			}
			else
			{
				if(NULL == pTemp->pLeft)
				{
					pTemp->pLeft = pNewNode;
					break;
				}
				else
					pTemp = pTemp->pLeft;
			}
		}
	}
}

void PreOrder(struct node *pRoot)
{
	if(NULL == pRoot)
		return;
		
	printf("%d\t",pRoot->iData);
	PreOrder(pRoot->pLeft);
	PreOrder(pRoot->pRight);
}

void InOrder(struct node *pRoot)
{
	if(NULL == pRoot)
		return;
		
	InOrder(pRoot->pLeft);
	printf("%d\t",pRoot->iData);
	InOrder(pRoot->pRight);
}

void PostOrder(struct node *pRoot)
{
	if(NULL == pRoot)
		return;
	
	PostOrder(pRoot->pLeft);
	PostOrder(pRoot->pRight);
	printf("%d\t",pRoot->iData);
}

int CountNodes(struct node *pRoot)
{
	if(NULL == pRoot)
		return 0;
	
	return (1 + CountNodes(pRoot->pLeft) + CountNodes(pRoot->pRight));
}

int LeafCount(struct node *pRoot)
{
	if(NULL == pRoot)
		return 0;
		
	if(NULL == pRoot->pLeft && NULL == pRoot->pRight)
		return 1;
	
	return (LeafCount(pRoot->pLeft) + LeafCount(pRoot->pRight));
}
/*  
	O/P:-

		1.Create
		2.Insert
		3.PreOrder
		4.InOrder
		5.PostOrder
		6.Count Nodes
		7.Leaf Count
		8.Exit

		Enter Choice :  1

		How many number of elements you want to insert: 3

		Element 1:      11

		Element 2:      22

		Element 3:      33

		1.Create
		2.Insert
		3.PreOrder
		4.InOrder
		5.PostOrder
		6.Count Nodes
		7.Leaf Count
		8.Exit

		Enter Choice :  2

		How many number of elements you want to insert: 3

		Element 1:      12

		Element 2:      13

		Element 3:      14

		1.Create
		2.Insert
		3.PreOrder
		4.InOrder
		5.PostOrder
		6.Count Nodes
		7.Leaf Count
		8.Exit

		Enter Choice :  3
		11      22      12      13      14      33
		1.Create
		2.Insert
		3.PreOrder
		4.InOrder
		5.PostOrder
		6.Count Nodes
		7.Leaf Count
		8.Exit

		Enter Choice :  4
		11      12      13      14      22      33
		1.Create
		2.Insert
		3.PreOrder
		4.InOrder
		5.PostOrder
		6.Count Nodes
		7.Leaf Count
		8.Exit

		Enter Choice :  5
		14      13      12      33      22      11
		1.Create
		2.Insert
		3.PreOrder
		4.InOrder
		5.PostOrder
		6.Count Nodes
		7.Leaf Count
		8.Exit

		Enter Choice :  6

		Total Nodes = 6

		1.Create
		2.Insert
		3.PreOrder
		4.InOrder
		5.PostOrder
		6.Count Nodes
		7.Leaf Count
		8.Exit

		Enter Choice :  7

		Total Leaf Nodes = 2

		1.Create
		2.Insert
		3.PreOrder
		4.InOrder
		5.PostOrder
		6.Count Nodes
		7.Leaf Count
		8.Exit

		Enter Choice :  8

*/
