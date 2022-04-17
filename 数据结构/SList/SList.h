#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;

typedef struct SListNode
{
	SLDataType val;//�����ֵ
	struct SListNode* next;
}SLTNode;
// ��ӡ
void SListPrint(SLTNode* phead);

// �������Ϊ��ʱ���½�һ��
SLTNode* BuySListNode(SLDataType x);

// ͷ��
void SListPushFront(SLTNode** phead, SLDataType x);
// β��
void SListPushBack(SLTNode** phead, SLDataType x);
// βɾ
void SListPopBack(SLTNode** phead);
// ͷɾ
void SListPopFront(SLTNode** phead);

// ���������ж��ٸ�����
int SListSize(SLTNode* phead);

// ���ҵ�k���ڵ�
SLTNode* SListFind(SLTNode* phead, int k);

// ��������posλ��֮�����x
void SListInsertAfter(SLTNode** pos, SLDataType x);

// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SLTNode** pos);

//�Ƴ�����Ԫ�� ����ֵΪx��Ԫ��
void removeElements(SLTNode** phead, SLDataType x);

// ��ת����

SLTNode* SListreverse(SLTNode** phead);

//�������м�Ľڵ�
SLTNode* SListmiddle(SLTNode* phead);

// ���ҵ�����K���ڵ�
SLTNode* SListFindKth(SLTNode* phead, int k);

// �ϲ�������������  ʹ���Ϊһ���µ��������� ���ﲻ������
SLTNode* SListmergeTwo(SLTNode* phead1, SLTNode* phead2);

//��������
// ���ﲻд�ˡ���Ҫ�Ǵ��븴�ã���ת�ȽϾͿ����ˡ�