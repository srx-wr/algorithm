#include<iostream>
using namespace std;

const int N = 10;
int q[N];
bool st[N]; // 选过就不能再选择
int n;
// u表示在选择第几个数
void dfs(int u)
{
	if (u == n + 1)
	{
		for(int i = 1; i <= n;i ++)
		{
			printf("%d ", q[i]);
		}
		puts("");
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!st[i])
		{
			st[i] = true;
			q[u] = i;
			dfs(u + 1);
			st[i] = false;
			q[u] = 0;
		}
	}


}

int  main()
{
	cin >> n;
	dfs(1);
	return 0;
}