#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int BTDatatype;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* pleft;  //����
	struct BinaryTreeNode* pright; //�Һ���
	BTDatatype data;
}TreeNode;

