#include<iostream>
using namespace std;
/// <summary>
/// 去他妈的bfs 我直接暴力枚举不好啊
/// </summary>
/// <returns></returns>
bool check(int i, int j,  int k)
{
	int sum = 0;
	while (i)
	{
		sum += i % 10;
		i /= 10;
	}
	while (j)
	{
		sum += j % 10;
		j /= 10;
	}
	if (sum <= k) return true;
	return false;
}

int main()
{
	int k, n, m,ans = 0;
	cin >> k >> n >> m ;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (check(i, j, k))
			{
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}