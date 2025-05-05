#define MAX 15
struct Queue
{
	struct Node *pNode;
	struct Queue *pNext;
};
int IsQueueFull(struct Queue *pHead);
int IsQueueEmpty(struct Queue *pHead);
int CountNodesQueue(struct Queue *pHead);
struct Node * DeQueue(struct Queue **ppHead);
void EnQueue(struct Queue **ppHead,struct Node *pHead);
