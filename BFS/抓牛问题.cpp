// �˿����� a - 1, a + 1 a *2 ����a����ǰ �˵�λ�ã�k����ţ��λ�� ����ţ����Զ����Ϊ 1000000
#include<iostream>
using namespace std;
const int N = 2e6 + 10;
int a, k;
bool vis[N];
int q[N];//����
bool check(int x)
{
	return x > 0 && (k - x < (int)1e6) && !vis[x];
}

int dfs()
{
	int cnt = 0;// ��ʾ����
	int hh = 1, tt = 1;
	while (hh <= tt)
	{
		int size = tt - hh + 1;
		while (size--)
		{
			int t = q[hh++];//hh = 2;
			if (t == k) return cnt;
			if (check(t - 1))
			{
				vis[t - 1] = true;
				q[++tt] = t - 1;
			}
			if (check(t + 1))
			{
				vis[t + 1] = true;
				q[++tt] = t + 1;
			}
			if (check(t * 2))
			{
				vis[t + 1] = true;
				q[++tt] = t * 2; // tt = 5
			}
		}
		cnt++;
	}
}

int main()
{
	cin >> a >> k;
	vis[a] = true;
	if (a == k) cout << 0 << endl;
	else if (a > k) cout << a - k << endl;
	else
		q[1] = a; cout << dfs() << endl;
	return 0;
}