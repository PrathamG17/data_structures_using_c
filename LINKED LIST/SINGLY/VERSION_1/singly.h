struct Node
{
	int iNo;
	struct Node *pNext;
};
void Display(struct Node *pHead);
int CountNodes(struct Node *pHead);
void DeleteAll(struct Node **ppHead);
int DeleteLast(struct Node **ppHead);
int DeleteFirst(struct Node **ppHead);
void ReverseDisplay(struct Node *pHead);
void PhysicalReverse(struct Node **ppHead);
void InsertLast(struct Node **ppHead,int iData);
void InsertFirst(struct Node **ppHead,int iData);
int DeleteAtPosition(struct Node **ppHead,int iPos);
int SearchAllOccurrence(struct Node *pHead,int iKey);
int SearchLastOccurrence(struct Node *pHead,int iKey);
int SearchFirstOccurrence(struct Node *pHead,int iKey);
void ConcatList(struct Node **ppHead1,struct Node **ppHead2);
void InsertAtPosition(struct Node **ppHead,int iData,int iPos);
void ConcatAtPosition(struct Node **ppHead1,struct Node **ppHead2,int iPos);
