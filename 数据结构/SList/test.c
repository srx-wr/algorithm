#include"SList.h"

void TestList()
{
	SLTNode* n1 = NULL;
	SListPushBack(&n1, 1);
	SListPushBack(&n1, 2);
	SListPushBack(&n1, 3);
	SListPushBack(&n1, 4);
	SListPushBack(&n1, 5);

	SListPrint(n1); // 1 2 3 4 5

	SListPushFront(&n1, -1);
	SListPrint(n1);// -1 1 2 3 4 5
	SListPushBack(&n1, 6);
	SListPrint(n1); // -1 1 2 3 4 5 6 
	SListPopBack(&n1);
	SListPrint(n1);// -1 1 2 3 4 5
	SListPopFront(&n1);
	SListPopFront(&n1);
	SListPopFront(&n1);
	SListPrint(n1); // 3 4 5 
	printf("%d\n", SListSize(n1));// 3
	SLTNode* pos = SListFind(n1, 1);
	SListInsertAfter(&pos, 30);
	SListPrint(n1); // 3 30 4 5
	SListEraseAfter(&pos);
	SListPrint(n1);// 3  4 5
	SListreverse(&n1);
	SListPrint(n1);// 5  4  3
	SLTNode* middle = SListmiddle(n1);
	printf("%d\n", middle->val);//4
	SLTNode* k = SListFindKth(n1, 2);
	printf("%d\n", k->val); // 4
}

int main()
{
	TestList();

	return 0;
}