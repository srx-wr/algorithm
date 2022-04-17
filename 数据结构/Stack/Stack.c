#include"Stack.h"

void StackInit(Stack* ps)
{
	// ��ʼֱֵ��Ϊ�ռ���
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
	// �ж�ջ�ǲ������ˡ�
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

// ��ջ
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

// ��ȡջ��Ԫ��  ջ����ɾ����
STDataType StackTop(const Stack* ps)
{
	assert(ps);
	// ps��Ϊ��
	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];
}

// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}

