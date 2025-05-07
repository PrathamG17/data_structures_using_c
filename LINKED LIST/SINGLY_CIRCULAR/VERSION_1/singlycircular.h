struct Node
{
	int iNo;
	struct Node *pNext;
};
void Display(struct Node *pHead,struct Node *pTail);
void DeleteAll(struct Node **ppHead,struct Node **ppTail);
void InsertFirst(struct Node **ppHead,struct Node **ppTail,int iData);
void InsertLast(struct Node **ppHead,struct Node **ppTail,int iData);
void InsertAtPosition(struct Node **ppHead,struct Node **ppTail,int iPos,int iData);
int DeleteFirst(struct Node **ppHead,struct Node **ppTail);
int DeleteLast(struct Node **ppHead,struct Node **ppTail);
int DeleteAtPosition(struct Node **ppHead,struct Node **ppTail,int iPos);
void ConcatList(struct Node **ppHead1,struct Node **ppTail1,
				struct Node **ppHead2,struct Node **ppTail2);
void ConcatAtPosition(struct Node **ppHead1,struct Node **ppTail1,
					  struct Node **ppHead2,struct Node **ppTail2,int iPos);
void PhysicalReverse(struct Node **ppHead,struct Node **ppTail);
void ReverseDisplay(struct Node *ppHead,struct Node *ppTail);
int SearchAllOccurrence(struct Node *pHead,struct Node *pTail,int iKey);
int SearchLastOccurrence(struct Node *pHead,struct Node *pTail,int iKey);
int SearchFirstOccurrence(struct Node *pHead,struct Node *pTail,int iKey);
int CountNodes(struct Node *pHead,struct Node *pTail);
