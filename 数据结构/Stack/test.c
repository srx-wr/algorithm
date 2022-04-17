#include"Stack.h"
void StackTest()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	printf("%d\n", StackTop(&s));

	StackDestroy(&s);

}

int main()
{

	StackTest();
	return 0;
}

