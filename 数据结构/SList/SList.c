#include"SList.h"

// 打印链表
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
// 当链表为空时 新建链表
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

// 尾插
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
//头插
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
// 尾删
void SListPopBack(SLTNode** phead)
{
	// 1、没有节点
	// 2、只有一个节点
	// 3、有多个节点
	assert(phead);
	if (*phead == NULL)
	{
		printf("没有数据\n");
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
		printf("没有数据\n");
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

// 计算链表有多少个数据
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


// 查找第k个节点
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

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？  是单向的 不能逆着走
void SListInsertAfter(SLTNode** pos, SLDataType x)
{
	SLTNode* newNode = BuySListNode(x);
	newNode->next = (*pos)->next;
	(*pos)->next = newNode;
}
// 单链表删除pos位置之后的值

void SListEraseAfter(SLTNode** pos)
{
	if ((*pos)->next == NULL) return;
	SLTNode* prev = (*pos)->next;
	(*pos)->next = (*pos)->next->next;
	free(prev);
}
//移除链表元素 所有值为x的元素
void removeElements(SLTNode** phead, SLDataType x)
{
	if (*phead == NULL) return;
	SLTNode* cur = *phead;
	SLTNode* prev = NULL;
	while (cur)
	{
		if (cur->val == x)
		{
			// 要删除的节点的下一个节点先标记上
			SLTNode* next = cur->next;
			// 第一次判断，也就是首节点时
			if (prev == NULL)
			{
				free(cur);
				*phead = next;
				cur = next;
			}
			// 不是首节点时
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

// 反转链表
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

//查找最中间的节点
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
// 查找倒数第K个节点
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

// 合并两个有序链表  使其成为一个新的有序链表    这里不测试
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