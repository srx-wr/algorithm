#include<iostream>
using namespace std;
int n, m;
const int N = 30;
int q[N];

void dfs(int u, int star)
{
	// НижІ
	if (n - star + u < m) return;
	if (u == m + 1)
	{
		for (int i = 1; i <= m; i++)
		{
			printf("%d ", q[i]);
		}
		puts("");
		return;
	}

	for (int i = star; i <= n; i++)
	{
		q[u] = i;
		dfs(u + 1, i + 1);
	}
}

int main()
{
	cin >> n >> m;
	dfs(1, 1);
	return 0;
}