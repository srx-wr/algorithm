#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
using namespace std;

#define Inf 0x3f3f3f
const int N = 10;
int a[N][N];
int b[N][N];
int ans = 0x3f3f3f;
int check(int cnt)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			b[i][j] = a[i][j];// 备份
		}
	}
	for (int i = 1; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (!b[i - 1][j])// 如果上一行的灯开着 ,那么下一行的灯就必须点击一下
			{
				cnt++;
				b[i - 1][j] = !b[i - 1][j]; //上一行的中间
				if (j > 0) b[i][j - 1] = !b[i][j - 1]; // 当前行的左边
				if (j < 4)  b[i][j + 1] = !b[i][j + 1];// 当前行的右边
				b[i + 1][j] = !b[i + 1][j]; // 下一行的中间
				b[i][j] = !b[i][j]; // 当前要按的数据
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (b[4][i] == 0)
		{
			return Inf;
		}
	}
	return cnt;

}
void dfs(int u,int k)
{
	if (u == 5)
	{
		ans = min(ans, check(k));
		return;
	}

	// 不开 
	dfs(u + 1, k);

	//开
	a[0][u] = !a[0][u];
	if (u - 1 >= 0)
		a[0][u - 1] = !a[0][u - 1];
	if (u + 1 < 5)
		a[0][u + 1] = !a[0][u + 1];
	a[1][u] = !a[1][u];
	dfs(u + 1, k + 1);
	// 状态恢复
	a[0][u] = !a[0][u];
	if (u - 1 >= 0)
		a[0][u - 1] = !a[0][u - 1];
	if (u + 1 < 5)
		a[0][u + 1] = !a[0][u + 1];
	a[1][u] = !a[1][u];
}

int main()
{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		dfs(0,0);
		if (ans < 8) cout << ans << endl;
		else cout << -1 << endl;
	return 0;
}