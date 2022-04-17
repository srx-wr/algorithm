
#include"SeqList.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
//初始化线性表
void SeqListInit(SeqList* ps1)
{
	assert(ps1);

	ps1->a = NULL;
	ps1->capacity = ps1->size = 0;
}
void SeqListCheck(SeqList* ps1)
{
	size_t newcapacity = ps1->capacity == 0 ? 4 : ps1->capacity * 2;
	ps1->a = realloc(ps1->a, newcapacity * sizeof(SQDataType));
	ps1->capacity = newcapacity;
	if (ps1->a == NULL)
	{
		printf("扩容失败！！！！！！！");
		exit(-1);
	}
}
void SeqListPrint(const SeqList* ps1)
{
	assert(ps1);
	for (int i = 0; i < ps1->size; i++)
	{
		printf("%d ", ps1->a[i]);
	}
	printf("\n");
}
//销毁线性表
void SeqListDestroy(SeqList* ps1)
{
	assert(ps1);

	if (ps1->a != NULL)
	{
		free(ps1->a);
	}
	ps1->capacity = ps1->size = 0;
}
//尾插
void SeqListPushBack(SeqList* ps1, SQDataType x)
{
	assert(ps1);

	if (ps1->capacity == ps1->size)
	{
		SeqListCheck(ps1);
	}

	ps1->a[ps1->size] = x;
	ps1->size++;
}
//头插
void SeqListPushFront(SeqList* ps1, SQDataType x)
{
	assert(ps1);
	if (ps1->capacity == ps1->size)
	{
		SeqListCheck(ps1);
	}
	SQDataType tmp = ps1->a[ps1->size - 1];
	SQDataType end = ps1->size;
		while (end >= 0)
		{
			ps1->a[end + 1] = ps1->a[end];
			end--;
		}
		ps1->a[0] = x;
		ps1->size++;
}

//尾删
void SeqListPopBack(SeqList* ps1)
{
	assert(ps1);
	ps1->size--;
}

//头删
void SeqListPopFront(SeqList* ps1)
{
	assert(ps1);
	
	for (int i = 0; i < ps1->size; i++)
	{
		ps1->a[i] = ps1->a[i + 1];
	}
	ps1->size--;
}

// 查找数据
int SeqListSearchData(const SeqList* ps1, SQDataType x)
{
	assert(ps1);
	for (int i = 0; i < ps1->size; i++)
	{
		if (ps1->a[i] == x)
		{
			return i;
		}
	}
	//没找到
	return -1;
}
//在任意位置插入数据
void SeqListInsert(SeqList* ps1, int pos, SQDataType x)
{
	assert(ps1);
	//扩容
	if (ps1->capacity == ps1->size)
	{
		SeqListCheck(ps1);
	}
	int end = ps1->size - 1;
	while (end >= pos)
	{
		ps1->a[end + 1] = ps1->a[end];
		end --;
	}
	ps1->a[pos] = x;
	ps1->size++;
}

// 删除任意位置的数据
void SeqListEarse(SeqList* ps1, int pos)
{
	assert(ps1);
	while (pos < ps1->size - 1)
	{
		ps1->a[pos] = ps1->a[pos + 1];
		pos++;
	}
	ps1->size--;
}