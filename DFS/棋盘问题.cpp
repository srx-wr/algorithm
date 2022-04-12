/*
问题：在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。
要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，请编程求解对于给定形状和大小的棋盘，
摆放k个棋子的所有可行的摆放方案C。

input： 输入含有多组测试数据。 每组数据的第一行是两个正整数，n k，用一个空格隔开，
表示了将在一个n*n的矩阵内描述棋盘，以及摆放棋子的数目。 n <= 8 , k <= n 当为-1 -1时表示输入结束。 
随后的n行描述了棋盘的形状：每行有n个字符，其中 # 表示棋盘区域， . 表示空白区域（数据保证不出现多余的空白行或者空白列）。

output：对于每一组数据，给出一行输出，输出摆放的方案数目C （数据保证C<2^31）。
*/

// 该问题同八皇后问题一一致。
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

int n, k, res, m;
//题目上最大为 8 我们开十个防止越界
const int N = 10;
char a[6][6];
bool vis[N];// 判断当前列有没有数据
void dfs(int x) // 表示遍历到哪一行了
{
	if (m == k) // 表示棋子已经放完了
	{
		res++;
		return;
	}
	if (x == n)
	{
		return; // 越界了
	}
	// 每一行都需要放需要放
	for (int i = 0; i < n; i++) // 分别枚举每一列
	{
		if (!vis[i] && a[x][i] == '#')
		{
			vis[i] = true;
			m++;
			dfs(x + 1);
			// 状态恢复
			vis[i] = false;
			m--;
		}
	}

	// 当前行不用放 当k <= m 时。但是当前行不需要放棋子，那么我就要直接进入下一行，
	dfs(x + 1);
}

int main()
{
	while (scanf("%d%d", &n, &k))
	{
		res = 0;
		if (n == -1 && k == -1)
		{
			break;
		}

		for (int i = 0; i < n; i++) scanf("%s", a[i]);

		dfs(0);

		cout << res << endl;
	}
	return 0;
}