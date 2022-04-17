#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
}
int QueueEmpty(Queue* pq)
{
	return pq->ptail == NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QueueNode* newNode = (QueueNode* )malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		printf("malloc exit");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	if (pq->ptail == NULL)
	{
		pq->ptail = pq->phead = newNode;
	}
	else
	{
		pq->ptail->next = newNode;
		pq->ptail = newNode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	if (pq->phead->next == NULL)
	{
		free(pq->phead);
		pq->phead = NULL;
		pq->ptail = NULL;
	}
	else
	{
		QueueNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;

	}
}
//销毁队列
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->phead;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->phead = pq->ptail = NULL;
}

QDataType QueueFront(const Queue* pq)
{
	assert(pq);
	// 判断对头是不是为空 
	assert(pq->phead);

	return pq->phead->data;
}

// 获取队列队尾元素
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);

	return pq->ptail->data;
}
// 获取队列中有效元素个数
int QueueSize(Queue* pq)
{
	QueueNode* cur = pq->phead;
	int cnt = 0;
	while (cur != NULL)
	{
		cnt++;
		cur = cur->next;
	}
	return cnt;
}