#pragma once


typedef int SQDataType;

typedef struct SeqList
{
	SQDataType* a;
	int size;
	int capacity;
}SeqList;
//初始化和销毁
void SeqListInit(SeqList* ps1);
void SeqListDestroy(SeqList* ps1);

void SeqListPrint(SeqList* ps1);
void SeqListCheck(SeqList* ps1);

//尾插头插  尾删头删
//尾插
void SeqListPushBack(SeqList* ps1,SQDataType x);
//头插
void SeqListPushFront(SeqList* ps1, SQDataType x);

//尾删
void SeqListPopBack(SeqList* ps1);
//头删
void SeqListPopFront(SeqList* ps1);
// 查找数据
int SeqListSearchData(SeqList* ps1, SQDataType x);
// 任意位置插入数据 
void SeqListInsert(SeqList* ps1,int pos,SQDataType x);

// 删除任意位置的数据
void SeqListEarse(SeqList* ps1, int pos);