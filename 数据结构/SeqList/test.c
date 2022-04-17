#include<stdio.h>
#include<stdlib.h>
#include"SeqList.h"

void test1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	
	SeqListPrint(&s); // 1 2 3 4 5 
	printf("%d\n", SeqListSearchData(&s, 5)); // 4
	SeqListPushFront(&s, -1);
	SeqListPrint(&s); // -1 1 2 3 4 5

	////尾删三个
	//SeqListPopBack(&s);
	//SeqListPopBack(&s);
	//SeqListPopBack(&s);
	//SeqListPrint(&s); // -1 1 2
	////头删两个
	//SeqListPopFront(&s);
	//SeqListPopFront(&s);
	//SeqListPrint(&s); // 2
	//SeqListDestroy(&s);

	//3号位置插7
	SeqListInsert(&s, 3, 7);
	SeqListPrint(&s); // -1 1 2 7 3 4 5
	SeqListEarse(&s, 4);
	SeqListPrint(&s); // -1 1 2 7 4 5
}

int main()
{
	test1();
	return 0;
}