struct Node
{
	struct Node *pLeft;
	int iNo;
	struct Node *pRight;
};
int Height(struct Node *pHead);
void InOrder(struct Node *pHead);
void PreOrder(struct Node *pHead);
void PostOrder(struct Node *pHead);
int CountNodes(struct Node *pHead);
int LargestBST(struct Node *pHead);
int SmallestBST(struct Node *pHead);
void LevelOrder(struct Node *pHead);
void DeleteAll(struct Node **ppHead);
int LeafNodeCount(struct Node *pHead);
int NonLeafNodeCount(struct Node *pHead);
void InsertBST(struct Node **ppHead,int iData);
void DeleteNode(struct Node **ppHead,int iData);
struct Node * SearchRecursive(struct Node *pHead,int iKey);
struct Node * SearchNonRecursive(struct Node *pHead,int iKey);
