#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int STDataType;

// fist in last out 先进后出，。
typedef struct Stack
{
	STDataType* a;
	int top;//栈顶
	int capatity; // 容量
}Stack;
// 初始化栈
void StackInit(Stack* ps);
// 入栈
void StackPush(Stack* ps, STDataType x);
// 出栈
void StackPop(Stack* ps);
// 判断是否为空
int StackEmpty(Stack* ps);
// 销毁栈
void StackDestroy(Stack* ps);
// 获取栈顶元素
STDataType StackTop(Stack* ps);

// 获取栈中有效元素个数
int StackSize(Stack* ps);