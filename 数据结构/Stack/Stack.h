#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int STDataType;

// fist in last out �Ƚ��������
typedef struct Stack
{
	STDataType* a;
	int top;//ջ��
	int capatity; // ����
}Stack;
// ��ʼ��ջ
void StackInit(Stack* ps);
// ��ջ
void StackPush(Stack* ps, STDataType x);
// ��ջ
void StackPop(Stack* ps);
// �ж��Ƿ�Ϊ��
int StackEmpty(Stack* ps);
// ����ջ
void StackDestroy(Stack* ps);
// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps);

// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps);