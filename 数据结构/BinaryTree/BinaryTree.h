#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int BTDatatype;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* pleft;  //×óº¢×Ó
	struct BinaryTreeNode* pright; //ÓÒº¢×Ó
	BTDatatype data;
}TreeNode;

