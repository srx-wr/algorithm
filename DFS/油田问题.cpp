#define _CRT_SECURE_NO_WARNINGS 1


/*
* 问题：GeoSurvComp地质调查公司负责探测地下石油储藏。 GeoSurvComp现在在一块矩形区域探测石油，并把这个大区域分成了很多小块。
他们通过专业设备，来分析每个小块中是否蕴藏石油。如果这些蕴藏石油的小方格相邻，那么他们被认为是同一油藏的一部分。在这块矩形
区域，可能有很多油藏。你的任务是确定有多少不同的油藏。

input: 输入可能有多个矩形区域（即可能有多组测试）。每个矩形区域的起始行包含m和n，表示行和列的数量，

1<=n,m<=100，如果m =0表示输入的结束，接下来是n行，每行m个字符。每个字符对应一个小方格，并且要么是’*’，代表没有油，要么是’@’，表示有油。

output: 对于每一个矩形区域，输出油藏的数量。两个小方格是相邻的，当且仅当他们水平或者垂直或者对角线相邻（即8个方向）。
*/
/*
*  输入：n m 表示n行m列
		 4  5
		*@**@		
		*@**@
		@@**@
		@@@*@
*/


#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

char a[6][6];
int n, m;
int res = 0;
int dir[8][2] = { 1,0,-1,0,0,1,0,-1,1,1,-1,1,1,-1,-1,-1 };
///	dir[i][0] 表示x 坐标 dir[i][1] 表示y 坐标

bool check(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y <= m && a[x][y] == '@';
}

bool dfs(int x, int y)
{
	if (check(x, y))
	{
		// 表示已经被标记
		a[x][y] = '*';
		// 如果 当前位置为石油的位置，那么就向他的八个方向进行查找。
		for (int i = 0; i < 8; i++)
		{
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			dfs(xx, yy);
		}
		return true;
	}
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dfs(i, j))
			{
				res++;
			}
		}
	}
	cout << res << endl;
	return 0;
}