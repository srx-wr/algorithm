#include<string>
#include<iostream>
using namespace std;
const int N = 20;
int st[N]; // 0 ��ʾ������  1 ��ʾ����  2 ��ʾ������
int n;

void dfs(int u)
{
	if (u == n + 1)
	{
		for (int i = 1; i <= n; i++)
			if (st[i] == 1)
			{
				printf("%d", i);
			}
		puts("");
		return;
	}

	// ������
	st[u] = 2;
	dfs(u + 1);
	st[u] = 0;

	st[u] = 1;
	dfs(u + 1);
	st[u] = 0;
}

int main()
{
	cin >> n;
	dfs(1);


	return 0;
}