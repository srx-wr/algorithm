#include<iostream>
using namespace std;
const int N = 20;
char q[N][N];
int n,row[N],col[N], dg[N], udg[N];//  列 ，对角线，反对角线

//void dfs(int u)
//{
//	// 递归基
//	if (u == n + 1)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= n; j++)
//			{
//				printf("%c", q[i][j]);
//			}
//			puts("");
//		}
//		puts("");
//		return;
//	}
//	// 遍历每一列
//	for (int i = 1; i <= n; i++)
//	{
//		if (!col[i] && !dg[n - u + i] && !udg[i + u])
//		{
//			col[i] = dg[n - u + i] = udg[i + u] = true;
//			q[u][i] = 'Q';
//			dfs(u + 1);
//			// 状态恢复
//			col[i] = dg[n - u + i] = udg[i + u] = false;
//			q[u][i] = '.';
//		}
//	}
//}
// x y 分别表示下标 s表示皇后的数量
void dfs(int x,int y,int s)
{
	if (s > n) return;

	if (y == n + 1)
	{
		y = 1;
		x += 1;
	}
	
	if (x == n + 1)
	{
		if (s == n)
		{
			for (int i = 1; i <= n; i++)
			{
				puts(q[i] + 1);
			}
			// 换行
			puts("");
		}
		return;
	}

	// 不放 
	dfs(x, y + 1, s);

	// 放
	if (!row[x] && !col[y] && !dg[n - x + y] && !udg[x + y])
	{
		row[x] = col[y] = dg[n - x + y] = udg[x + y] = true;
		q[x] = 'Q';
		dfs(x, y + 1, s + 1); // 放数据了 自然要加一
		row[x] = col[y] = dg[n - x + y] = udg[x + y] = false;
		q[x][y] = '.';
	}
}


int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			q[i][j] = '.';
		}
	}
	//dfs(1);
	dfs(1, 1, 0);
	return 0;
}
