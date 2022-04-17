#include"SList.h"

// ��ӡ����
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}
// ������Ϊ��ʱ �½�����
SLTNode* BuySListNode(SLDataType x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	if (node == NULL)
	{
		printf("malloc exit");
		exit(-1);
	}
	node->val = x;
	node->next = NULL;
	return node;
}

// β��
void SListPushBack(SLTNode** phead, SLDataType x)
{
	if (*phead == NULL)
	{
		SLTNode* newNode = BuySListNode(x);
		*phead = newNode;
	}
	else
	{
		SLTNode* tail = *phead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		SLTNode* newNode = BuySListNode(x);
		tail->next = newNode;
	}
}
//ͷ��
void SListPushFront(SLTNode** phead, SLDataType x)
{
	SLTNode* newNode = BuySListNode(x);
	if (*phead == NULL)
	{
		*phead = newNode;
	}
	else
	{
		newNode->next = *phead;
		*phead = newNode;
	}
}
// βɾ
void SListPopBack(SLTNode** phead)
{
	// 1��û�нڵ�
	// 2��ֻ��һ���ڵ�
	// 3���ж���ڵ�
	assert(phead);
	if (*phead == NULL)
	{
		printf("û������\n");
		return;
	}
	else if((*phead)->next ==NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *phead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail->next);
		prev->next = NULL;
	}

}
void SListPopFront(SLTNode** phead)
{
	assert(phead);
	if (*phead == NULL)
	{
		printf("û������\n");
		return;
	}
	else if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	else
	{
		SLTNode* prev = *phead;
		*phead = (*phead)->next;
		free(prev);
	}
}

// ���������ж��ٸ�����
int SListSize(SLTNode* phead)
{
	if (phead == NULL)
	{
		return 0;
	}
	else
	{
		int k = 0;
		while (phead != NULL)
		{
			k++;
			phead = phead->next;
		}
		return k;
	}
}


// ���ҵ�k���ڵ�
SLTNode* SListFind(SLTNode* phead, int k)
{
	int size = SListSize(phead);
	if (k <= 0 || k > size)
	{
		return NULL;
	}
	SLTNode* tail = phead;
	while(--k)
	{
		tail = tail->next;
	}
	return tail;
}

// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿  �ǵ���� ����������
void SListInsertAfter(SLTNode** pos, SLDataType x)
{
	SLTNode* newNode = BuySListNode(x);
	newNode->next = (*pos)->next;
	(*pos)->next = newNode;
}
// ������ɾ��posλ��֮���ֵ

void SListEraseAfter(SLTNode** pos)
{
	if ((*pos)->next == NULL) return;
	SLTNode* prev = (*pos)->next;
	(*pos)->next = (*pos)->next->next;
	free(prev);
}
//�Ƴ�����Ԫ�� ����ֵΪx��Ԫ��
void removeElements(SLTNode** phead, SLDataType x)
{
	if (*phead == NULL) return;
	SLTNode* cur = *phead;
	SLTNode* prev = NULL;
	while (cur)
	{
		if (cur->val == x)
		{
			// Ҫɾ���Ľڵ����һ���ڵ��ȱ����
			SLTNode* next = cur->next;
			// ��һ���жϣ�Ҳ�����׽ڵ�ʱ
			if (prev == NULL)
			{
				free(cur);
				*phead = next;
				cur = next;
			}
			// �����׽ڵ�ʱ
			else
			{
				prev->next = next;
				free(cur);
				cur = prev->next;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

// ��ת����
SLTNode* SListreverse(SLTNode** phead)
{
	if (*phead == NULL || (*phead)->next == NULL) return *phead;

	SLTNode* n1 = NULL, *n2 = *phead, *n3 = (*phead)->next;

	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3)
		{
			n3 = n3->next;
		}
	}
	(*phead) = n1;
	return n1;
}

//�������м�Ľڵ�
SLTNode* SListmiddle(SLTNode* phead)
{
	if (phead == NULL || phead->next == NULL) return phead;
	SLTNode* fast = phead;
	SLTNode* slow = phead;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
// ���ҵ�����K���ڵ�
SLTNode* SListFindKth(SLTNode* phead,int k)
{
	if (k <= 0) return NULL;
	if (phead == NULL) return NULL;
	SLTNode* fast = phead;
	SLTNode* slow = phead;
	while (--k)
	{
		if (fast->next != NULL)
		{
			fast = fast->next;
		}
		else
		{
			return NULL;
		}
	}
	while (fast->next != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}

	return slow;
}

// �ϲ�������������  ʹ���Ϊһ���µ���������    ���ﲻ����
SLTNode* SListmergeTwo(SLTNode* phead1, SLTNode* phead2)
{
	SLTNode* newhead = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* tmp = newhead, *l1 = phead1, *l2 = phead2;

	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val < l2->val)
		{
			tmp->next = l1;
			l1 = l1->next;
			tmp = tmp->next;
		}
		else
		{
			tmp->next = l2;
			l2 = l2->next;
			tmp = tmp->next;
		}
	}

	if (l1 == NULL)
	{
		tmp->next = l2;
	}
	if (l2 == NULL)
	{
		tmp->next = l1;
	}

	return newhead->next;
}