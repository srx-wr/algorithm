#include"Stack.h"

void StackInit(Stack* ps)
{
	// 初始值直接为空即可
	ps->a = NULL;
	ps->top = 0;
	ps->capatity = 0;
}

int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
		
}



void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	// 判断栈是不是满了。
	if (ps->top == ps->capatity)
	{
		int newCapacity = ps->capatity == 0 ? 4 : ps->capatity * 2;
		STDataType* tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capatity = newCapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

// 出栈
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}
void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->a)
	{
		free(ps->a);
	}
	ps->a = NULL;
	ps->top = 0;
	ps->capatity = 0;
}

// 获取栈顶元素  栈顶不删除版
STDataType StackTop(const Stack* ps)
{
	assert(ps);
	// ps不为空
	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];
}

// 获取栈中有效元素个数
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}

