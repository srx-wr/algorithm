#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int QDataType;
typedef struct  QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;	

typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
}Queue;

//初始化队列
void QueueInit(Queue* pq);

void QueuePush(Queue* pq,QDataType x);

void QueuePop(Queue* pq);

int QueueEmpty(Queue* pq);
//销毁队列
void QueueDestroy(Queue* pq);

// 获取队列头部元素
QDataType QueueFront(Queue* pq);
// 获取队列队尾元素
QDataType QueueBack(Queue* pq);

// 获取队列中有效元素个数
int QueueSize(Queue* pq);