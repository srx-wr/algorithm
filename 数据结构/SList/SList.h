#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;

typedef struct SListNode
{
	SLDataType val;//存放数值
	struct SListNode* next;
}SLTNode;
// 打印
void SListPrint(SLTNode* phead);

// 如果链表为空时就新建一个
SLTNode* BuySListNode(SLDataType x);

// 头插
void SListPushFront(SLTNode** phead, SLDataType x);
// 尾插
void SListPushBack(SLTNode** phead, SLDataType x);
// 尾删
void SListPopBack(SLTNode** phead);
// 头删
void SListPopFront(SLTNode** phead);

// 计算链表有多少个数据
int SListSize(SLTNode* phead);

// 查找第k个节点
SLTNode* SListFind(SLTNode* phead, int k);

// 单链表在pos位置之后插入x
void SListInsertAfter(SLTNode** pos, SLDataType x);

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SLTNode** pos);

//移除链表元素 所有值为x的元素
void removeElements(SLTNode** phead, SLDataType x);

// 反转链表

SLTNode* SListreverse(SLTNode** phead);

//查找最中间的节点
SLTNode* SListmiddle(SLTNode* phead);

// 查找倒数第K个节点
SLTNode* SListFindKth(SLTNode* phead, int k);

// 合并两个有序链表  使其成为一个新的有序链表 这里不测试了
SLTNode* SListmergeTwo(SLTNode* phead1, SLTNode* phead2);

//回文链表
// 这里不写了。主要是代码复用，反转比较就可以了。