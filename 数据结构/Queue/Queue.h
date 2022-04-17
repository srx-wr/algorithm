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

//��ʼ������
void QueueInit(Queue* pq);

void QueuePush(Queue* pq,QDataType x);

void QueuePop(Queue* pq);

int QueueEmpty(Queue* pq);
//���ٶ���
void QueueDestroy(Queue* pq);

// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* pq);
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* pq);

// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* pq);