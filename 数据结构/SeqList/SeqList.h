#pragma once


typedef int SQDataType;

typedef struct SeqList
{
	SQDataType* a;
	int size;
	int capacity;
}SeqList;
//��ʼ��������
void SeqListInit(SeqList* ps1);
void SeqListDestroy(SeqList* ps1);

void SeqListPrint(SeqList* ps1);
void SeqListCheck(SeqList* ps1);

//β��ͷ��  βɾͷɾ
//β��
void SeqListPushBack(SeqList* ps1,SQDataType x);
//ͷ��
void SeqListPushFront(SeqList* ps1, SQDataType x);

//βɾ
void SeqListPopBack(SeqList* ps1);
//ͷɾ
void SeqListPopFront(SeqList* ps1);
// ��������
int SeqListSearchData(SeqList* ps1, SQDataType x);
// ����λ�ò������� 
void SeqListInsert(SeqList* ps1,int pos,SQDataType x);

// ɾ������λ�õ�����
void SeqListEarse(SeqList* ps1, int pos);