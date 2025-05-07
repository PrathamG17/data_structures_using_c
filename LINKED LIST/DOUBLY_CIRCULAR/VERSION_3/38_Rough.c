#include<stdio.h>
#include<malloc.h>

struct Node
{
	struct Node *pPrev;
	int iNo;
	struct Node *pNext;
};

void Display(struct Node *pHead,struct Node *pTail);
int CountNodes(struct Node *pHead,struct Node *pTail);
void DeleteAll(struct Node **ppHead,struct Node **ppTail);
int DeleteLast(struct Node **ppHead,struct Node **ppTail);
int DeleteFirst(struct Node **ppHead,struct Node **ppTail);
void ConcatList(struct Node **ppHead1,struct Node **ppTail1,
				struct Node **ppHead2,struct Node **ppTail2);
void ReverseDisplay(struct Node *ppHead,struct Node *ppTail);
void PhysicalReverse(struct Node **ppHead,struct Node **ppTail);
void InsertLast(struct Node **ppHead,struct Node **ppTail,int iData);
void InsertFirst(struct Node **ppHead,struct Node **ppTail,int iData);
int SearchAllOccurrence(struct Node *pHead,struct Node *pTail,int iKey);
int SearchLastOccurrence(struct Node *pHead,struct Node *pTail,int iKey);
int DeleteAtPosition(struct Node **ppHead,struct Node **ppTail,int iPos);
int SearchFirstOccurrence(struct Node *pHead,struct Node *pTail,int iKey);
void ConcatAtPosition(struct Node **ppHead1,struct Node **ppTail1,
					  struct Node **ppHead2,struct Node **ppTail2,int iPos);
void InsertAtPosition(struct Node **ppHead,struct Node **ppTail,int iPos,int iData);

int main(void)
{
	int iChoice;
	int iData;
	int iPos;
	int iPos1;
	struct Node *pFirst1=NULL;
	struct Node *pLast1=NULL;
	struct Node *pFirst2=NULL;
	struct Node *pLast2=NULL;
	
	while(1)
	{
		printf("\n\t--------Menu--------\n");
		printf("\n\t1)Insert.");
		printf("\n\t2)Delete.");
		printf("\n\t3)Search.");
		printf("\n\t4)Count.");
		printf("\n\t5)Concat.");
		printf("\n\t6)Reverse.");
		printf("\n\t7)Exit.");
		printf("\n\t--------------------\n");
		
		printf("\n\t-->>Enter Choice : ");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1: while(1)
					{
						printf("\n\t********Insert******\n");
						printf("\n\t1)Insert First.");
						printf("\n\t2)Insert Last.");
						printf("\n\t3)Insert At Position.");
						printf("\n\t4)Back.");
						printf("\n\t********************\n");
						
						printf("\n\t-->>Enter Choice : ");
						scanf("%d",&iChoice);
						
						if(4 == iChoice)
							break;
						
						if(3 == iChoice)
						{
							printf("\n\tEnter Position : ");
							scanf("%d",&iPos);
							
							if(iPos<=0||iPos>((iData=CountNodes(pFirst1,pLast1))+1))		
							{
								printf("\n\tInvalid Position\n\n");
								continue;
							}
							if(1==iPos)
								iChoice=1;
							if(iPos==iData+1)
								iChoice=2;
						}
						
						printf("\n\tEnter Data : ");
						scanf("%d",&iData);
						
						switch(iChoice)
						{
							case 1: InsertFirst(&pFirst1,&pLast1,iData);
									Display(pFirst1,pLast1);
									break;
									
							case 2: InsertLast(&pFirst1,&pLast1,iData);
									Display(pFirst1,pLast1);
									break;
									
							case 3: InsertAtPosition(&pFirst1,&pLast1,iPos,iData);
									Display(pFirst1,pLast1);
									break;
									
							default:printf("\n\tEnter Valid Choice.\n");
						}
					}
					break;
					
			case 2: if(NULL == pFirst1)
					{
						printf("\n\tList Is Empty.\n");
						break;
					}
					
					while(1)
					{
						printf("\n\t********Delete******\n");
						printf("\n\t1)Delete First.");
						printf("\n\t2)Delete Last.");
						printf("\n\t3)Delete At Position.");
						printf("\n\t4)Back.");
						printf("\n\t********************\n");
						
						printf("\n\t-->>Enter Choice : ");
						scanf("%d",&iChoice);
						
						if(4 == iChoice)
							break;
						
						switch(iChoice)
						{
							case 1: iChoice=DeleteFirst(&pFirst1,&pLast1);
									if(iChoice!=-1)
										printf("\n\tDeleted Data Is %d\n",iChoice);
									Display(pFirst1,pLast1);
									break;
									
							case 2: iChoice=DeleteLast(&pFirst1,&pLast1);
									if(iChoice!=-1)
										printf("\n\tDeleted Data Is %d\n",iChoice);
									Display(pFirst1,pLast1);
									break;
							
							case 3: printf("\n\tEnter Position. : ");
									scanf("%d",&iChoice);
									iData=DeleteAtPosition(&pFirst1,&pLast1,iChoice);
									if(iData!=-1)
										printf("\n\tDeleted Data Is %d\n",iData);
									Display(pFirst1,pLast1);
									break;
									
							default: printf("\n\tEnter Valid Choice.\n");
						}
					}
					break;
					
			case 3: if(NULL == pFirst1)
					{
						printf("\n\tList Is Empty.\n");
						break;
					}
					
					while(1)
					{	
						printf("\n\t********Search**********\n");
						printf("\n\t1)Search First Occurrence.");
						printf("\n\t2)Serach Last Occurrence.");
						printf("\n\t3)Search All Occurrence.");
						printf("\n\t4)Back.");
						printf("\n\t************************\n");
						
						printf("\n\t-->>Enter Choice : ");
						scanf("%d",&iChoice);
						
						if(4 == iChoice)
							break;
						
						printf("\n\tEnter Data : ");
						scanf("%d",&iData);
						
						switch(iChoice)
						{
							case 1: iChoice=SearchFirstOccurrence(pFirst1,pLast1,iData);
									if(iChoice!=0)
										printf("\n\tData %d Found First In Node %d.\n",iData,iChoice);
									else
										printf("\n\tData Not Found.\n");
									break; 
									
							case 2: iChoice=SearchLastOccurrence(pFirst1,pLast1,iData);
									if(iChoice!=0)
										printf("\n\tData %d Found Last In Node %d\n",iData,iChoice);
									else
										printf("\n\tData Not Found.\n");
									break; 
									
							case 3: iChoice=SearchAllOccurrence(pFirst1,pLast1,iData);
									if(iChoice!=0)
										printf("\n\t%d Found %d Times.\n",iData,iChoice);
									else
										printf("\n\t%d Found 0 Times.\n",iData);
									break; 
									
							default: printf("\n\tEnter Valid Choice.\n");
						}
					}
					break;
			
			case 4: iChoice=CountNodes(pFirst1,pLast1);
					printf("\n\tTotal Nodes = %d.\n",iChoice);
					break;

			case 5: while(1)
					{
						printf("\n\t********Concat******\n");
						printf("\n\t1)Concat List.");
						printf("\n\t2)Concat At Position.");
						printf("\n\t3)Back.");
						printf("\n\t********************\n");
						
						if(3 == iChoice)
							break;
						
						printf("\n\t-->>Enter Choice : ");
						scanf("%d",&iChoice);
						
						switch(iChoice)
						{
							case 1: while(1)
									{
										printf("\n\t********Insert******\n");
										printf("\n\t1)Insert First.");
										printf("\n\t2)Insert Last.");
										printf("\n\t3)Insert At Position.");
										printf("\n\t4)Back.");
										printf("\n\t********************\n");
										
										printf("\n\t-->>Enter Choice : ");
										scanf("%d",&iChoice);
										
										if(4 == iChoice)
										{
											ConcatList(&pFirst1,&pLast1,&pFirst2,&pLast2);
											Display(pFirst1,pLast1);
											break;
										}
										
										if(3 == iChoice)
										{
											printf("\n\tEnter Position : ");
											scanf("%d",&iPos);
											
											if(iPos<=0||iPos>((iData=CountNodes(pFirst2,pLast2))+1))		
											{
												printf("\n\tInvalid Position\n\n");
												continue;
											}
											if(1==iPos)
												iChoice=1;
											if(iPos==iData+1)
												iChoice=2;
										}
										
										printf("\n\tEnter Data : ");
										scanf("%d",&iData);
										
										switch(iChoice)
										{
											case 1: InsertFirst(&pFirst2,&pLast2,iData);
													Display(pFirst2,pLast2);
													break;
													
											case 2: InsertLast(&pFirst2,&pLast2,iData);
													Display(pFirst2,pLast2);
													break;
													
											case 3: InsertAtPosition(&pFirst2,&pLast2,iPos,iData);
													Display(pFirst2,pLast2);
													break;
													
											default:printf("\n\tEnter Valid Choice.\n");
										}
									}
									break;
									
							case 2: printf("\n\tEnter Position : ");
									scanf("%d",&iPos1);
									if(iPos1<=0||iPos1>((iData=CountNodes(pFirst1,pLast1))+1))
									{
										printf("\n\tInvalid Position.\n");
										break;
									}
									else
									{	
										while(1)
										{
											printf("\n\t********Insert******\n");
											printf("\n\t1)Insert First.");
											printf("\n\t2)Insert Last.");
											printf("\n\t3)Insert At Position.");
											printf("\n\t4)Back.");
											printf("\n\t********************\n");
											
											printf("\n\t-->>Enter Choice : ");
											scanf("%d",&iChoice);
											
											if(4 == iChoice)
											{
												ConcatAtPosition(&pFirst1,&pLast1,&pFirst2,&pLast2,iPos1);
												Display(pFirst1,pLast1);
												break;
											}
											
											if(3 == iChoice)
											{
												printf("\n\tEnter Position : ");
												scanf("%d",&iPos);
												
												if(iPos<=0||iPos>((iData=CountNodes(pFirst2,pLast2))+1))		//----used iData
												{
													printf("\n\tInvalid Position\n\n");
													continue;
												}
												if(1==iPos)
													iChoice=1;
												if(iPos==iData+1)
													iChoice=2;
											}
											
											printf("\n\tEnter Data : ");
											scanf("%d",&iData);
											
											switch(iChoice)
											{
												case 1: InsertFirst(&pFirst2,&pLast2,iData);
														Display(pFirst2,pLast2);
														break;
														
												case 2: InsertLast(&pFirst2,&pLast2,iData);
														Display(pFirst2,pLast2);
														break;
														
												case 3: InsertAtPosition(&pFirst2,&pLast2,iPos,iData);
														Display(pFirst2,pLast2);
														break;
														
												default:printf("\n\tEnter Valid Choice.\n");
											}
										}
									}
									break;
									
							default:printf("\n\tEnter Valid Choice.\n");
						}
					}
					break;
				
			case 6: if(NULL == pFirst1)
					{
						printf("\n\tList Is Empty.\n");
						break;
					}
					
					while(1)
					{
						printf("\n\t********Reverse*********\n");
						printf("\n\t1)Physical Reverse.");
						printf("\n\t2)Reverse Display.");
						printf("\n\t3)Back.");
						printf("\n\t************************\n");
						
						printf("\n\t-->Enter Choice : ");
						scanf("%d",&iChoice);
							
						if(3 == iChoice)
							break;
							
						switch(iChoice)
						{
							case 1: PhysicalReverse(&pFirst1,&pLast1);
									Display(pFirst1,pLast1);
									break;
									
							case 2: ReverseDisplay(pFirst1,pLast1);
									break;
																		
							default:printf("\n\tEnter Valid Choice.\n");
						}
														
					}
					
					break;
					
			case 7: if(pFirst1!=NULL)
					{
						DeleteAll(&pFirst1,&pLast1);
						pFirst1=pLast1=NULL;
					}
					
					if(pFirst2!=NULL)
					{
						DeleteAll(&pFirst2,&pLast2);
						pFirst2=pLast2=NULL;
					}
					return 0;
		
			default: printf("\n\tEnter Valid Choice.\n");
		}
	}
	
	return 0;
}
void InsertFirst(struct Node **ppHead,struct Node **ppTail,int iData)
{
	struct Node *pNewNode=NULL;
	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("MEMORY ALLOCATION FAILED\n\n");
		return;
	}
	pNewNode->iNo=iData;
	if(*ppHead!=NULL)
	{
		pNewNode->pNext=*ppHead;
		(*ppHead)->pPrev=pNewNode;
		*ppHead=pNewNode;
	}
	else
		*ppHead=*ppTail=pNewNode;
	(*ppHead)->pPrev=*ppTail;
	(*ppTail)->pNext=*ppHead;						//CIRCULAR EFFECT				
}
void InsertLast(struct Node **ppHead,struct Node **ppTail,int iData)
{
	struct Node *pNewNode=NULL;
	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("MEMORY ALLOCATION FAILED\n\n");
		return;
	}
	pNewNode->iNo=iData;
	if(*ppHead!=NULL)
	{
		pNewNode->pPrev=*ppTail;
		(*ppTail)->pNext=pNewNode;
		*ppTail=pNewNode;
	}
	else
		*ppHead=*ppTail=pNewNode;
	(*ppHead)->pPrev=*ppTail;
	(*ppTail)->pNext=*ppHead;					//CIRCULAR EFFECT
}
void InsertAtPosition(struct Node **ppHead,struct Node **ppTail,int iPos,int iData)
{
	int iCount;
	struct Node *pNewNode=NULL;
	struct Node *pTemp=NULL;
	if(iPos<=0||iPos>(iCount=CountNodes(*ppHead,*ppTail)+1))
	{
		printf("INVALID POSITION\n\n");
		return;
	}
	if(1==iPos)
	{
		InsertFirst(ppHead,ppTail,iData);
		return;
	}
	if(iPos==iCount+1)
	{
		InsertLast(ppHead,ppTail,iData);
		return;
	}
	pNewNode=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pNewNode)
	{
		printf("MEMORY ALLOCATION FAILED\n\n");
		return;
	}
	pNewNode->iNo=iData;
	pTemp=*ppHead;
	iCount=1;
	while(iCount<iPos-1)
	{
		iCount++;
		pTemp=pTemp->pNext;
	}
	pNewNode->pNext=pTemp->pNext;
	pTemp->pNext->pPrev=pNewNode;
	pNewNode->pPrev=pTemp;				
	pTemp->pNext=pNewNode;
}
int DeleteFirst(struct Node **ppHead,struct Node **ppTail)
{
	int iDelData;
	
	if(NULL==*ppHead)
		return -1;
	
	iDelData=(*ppHead)->iNo;
	
	if(*ppHead!=*ppTail)
	{
		*ppHead=(*ppHead)->pNext;
		
		(*ppTail)->pNext->pPrev=(*ppTail)->pNext->pNext=NULL;
		free((*ppTail)->pNext);
		
		(*ppHead)->pPrev=*ppTail;
		(*ppTail)->pNext=*ppHead;					//CIRCULAR EFFECT
	}
	else
	{
		(*ppHead)->pPrev=(*ppHead)->pNext=NULL;
		free(*ppHead);
		
		*ppHead=*ppTail=NULL;
	}
	
	return iDelData;
}
int DeleteLast(struct Node **ppHead,struct Node **ppTail)
{
	int iDelData;
	if(NULL == *ppHead)
		return -1;
	
	iDelData=(*ppTail)->iNo;
	
	if(*ppHead!=*ppTail)
	{
		*ppTail=(*ppTail)->pPrev;
		
		(*ppTail)->pNext->pPrev=(*ppTail)->pNext->pNext=NULL;
		free((*ppTail)->pNext);
		
		(*ppHead)->pPrev=*ppTail;
		(*ppTail)->pNext=*ppHead;						//CIRCULAR EFFECT
	}
	else
	{
		(*ppTail)->pPrev=(*ppTail)->pNext=NULL;
		free(*ppTail);
		
		*ppHead=*ppTail=NULL;
	}
	
	return iDelData;
}
int DeleteAtPosition(struct Node **ppHead,struct Node **ppTail,int iPos)
{
	int iCount=0;
	struct Node *pTemp=NULL;
	
	if(iPos<=0||iPos>(iCount=CountNodes(*ppHead,*ppTail)))
	{
		printf("\n\tInvalid Position.\n");
		return -1;
	}
	
	if(1==iPos)
		return DeleteFirst(ppHead,ppTail);
	
	if(iPos==iCount)
		return DeleteLast(ppHead,ppTail);	
	
	pTemp=*ppHead;
	iCount=1;
	while(iCount<iPos-1)
	{
		iCount++;
		pTemp=pTemp->pNext;
	}
	
	iCount=pTemp->pNext->iNo;
	pTemp->pNext=pTemp->pNext->pNext;
	
	pTemp->pNext->pPrev->pPrev=pTemp->pNext->pPrev->pNext=NULL;			
	free(pTemp->pNext->pPrev);
	
	pTemp->pNext->pPrev=pTemp;
	
	return iCount;
}
void Display(struct Node *pHead,struct Node *pTail)
{
	if(NULL==pHead)
	{
		printf("\n\tList Is Empty.\n");
		return;
	}
	printf("\n\t");
	do
	{
		printf("|%d|->",pHead->iNo);
		pHead=pHead->pNext;
	}while(pHead!=pTail->pNext);
	printf("\n");
}
int CountNodes(struct Node *pHead,struct Node *pTail)
{
	int iCount=0;
	
	if(NULL == pHead)
		return 0;
	
	do
	{
		iCount++;
		pHead=pHead->pNext;
	}while(pHead!=(pTail)->pNext);
	
	return iCount;
}
int SearchFirstOccurrence(struct Node *pHead,struct Node *pTail,int iKey)
{
	int iCount=0;
	if(NULL == pHead)
		return 0;
	
	do
	{
		iCount++;
		if(pHead->iNo==iKey)
			return iCount;
		pHead=pHead->pNext;
	}while(pHead!=(pTail)->pNext);
	return 0;
}
int SearchLastOccurrence(struct Node *pHead,struct Node *pTail,int iKey)
{
	int iCount=0;
	int iLastPos=0;
	if(NULL == pHead)
		return 0;
	
	do
	{
		iCount++;
		if(pHead->iNo==iKey)
			iLastPos=iCount;
		pHead=pHead->pNext;
	}while(pHead!=(pTail)->pNext);
	return iLastPos;
}
int SearchAllOccurrence(struct Node *pHead,struct Node *pTail,int iKey)
{
	int iCount=0;
		if(NULL == pHead)
		return 0;

	do
	{
		if(pHead->iNo==iKey)
			iCount++;
		pHead=pHead->pNext;
	}while(pHead!=(pTail)->pNext);
	return iCount;
}
void ConcatList(struct Node **ppHead1,struct Node **ppTail1,
				struct Node **ppHead2,struct Node **ppTail2)
{
	if(NULL==*ppHead2)
		return;
	if(NULL==*ppHead1)
	{
		*ppHead1=*ppHead2;
		*ppTail1=*ppTail2;
		*ppHead2=*ppTail2=NULL;
		return;
	}
	(*ppTail1)->pNext=*ppHead2;
	(*ppHead2)->pPrev=*ppTail1;							//CIRCULAR EFFECT			
	*ppTail1=*ppTail2;
	(*ppHead1)->pPrev=*ppTail1;						
	(*ppTail1)->pNext=*ppHead1;							//CIRCULAR EFFECT
	*ppHead2=*ppTail2=NULL;
}
void ConcatAtPosition(struct Node **ppHead1,struct Node **ppTail1,
					  struct Node **ppHead2,struct Node **ppTail2,int iPos)
{
	int iCount=0;
	struct Node *pTemp=NULL;
	iCount=CountNodes(*ppHead1,*ppTail1);
	// if(iPos<=0||iPos>iCount+1)
		// return;
	if(NULL==*ppHead2)
		return;
	if(1==iPos)
	{
		ConcatList(ppHead2,ppTail2,ppHead1,ppTail1);
		*ppHead1=*ppHead2;
		*ppTail1=*ppTail2;
		*ppHead2=*ppTail2=NULL;
		return;
	}
	if(iPos==iCount+1)
	{
		ConcatList(ppHead1,ppTail1,ppHead2,ppTail2);
		return;
	}
	pTemp=*ppHead1;
	iCount=1;
	while(iCount<iPos-1)
	{
		iCount++;
		pTemp=pTemp->pNext;
	}
	(*ppTail2)->pNext=pTemp->pNext;
	pTemp->pNext->pPrev=*ppTail2;							
	pTemp->pNext=*ppHead2;
	(*ppHead2)->pPrev=pTemp;							
	*ppHead2=*ppTail2=NULL;
}
void PhysicalReverse(struct Node **ppHead,struct Node **ppTail)
{
	struct Node *pCurrent=*ppHead;
	struct Node *pNext=NULL;
	if(NULL == *ppHead)
		return;

	while(1)
	{
		pNext=pCurrent->pNext;
		pCurrent->pNext=pCurrent->pPrev;
		pCurrent->pPrev=pNext;
		if(pNext==*ppHead)
			break;
		pCurrent=pNext;
	}
	*ppHead=pCurrent;
	*ppTail=pNext;
}
void ReverseDisplay(struct Node *pHead,struct Node *pTail)
{
	if(NULL == pHead)
	{
		printf("\n\tList Is Empty.\n");
		return;
	}
	printf("\n\t");
	do
	{
		printf("|%d|->",pTail->iNo);
		pTail=pTail->pPrev;
	}while(pTail!=pHead->pPrev);
	printf("\n");
}
void DeleteAll(struct Node **ppHead,struct Node **ppTail)
{
	struct Node *pTemp=NULL;
	(*ppTail)->pNext=NULL;
	while(*ppHead!=NULL)
	{
		pTemp=*ppHead;
		*ppHead=pTemp->pNext;
		pTemp->pPrev=pTemp->pNext=NULL;
		free(pTemp);
	}
	pTemp=NULL;
	*ppHead=NULL;
}
