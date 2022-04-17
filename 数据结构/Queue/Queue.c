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
//���ٶ���
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
	// �ж϶�ͷ�ǲ���Ϊ�� 
	assert(pq->phead);

	return pq->phead->data;
}

// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);

	return pq->ptail->data;
}
// ��ȡ��������ЧԪ�ظ���
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