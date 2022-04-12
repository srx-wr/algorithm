#include<iostream>
using namespace std;
typedef pair<int, int> PII;
const int N = 20;
int n, m;// n行 m列
PII q[N * N];
int a[N][N];
int b[N][N];//表示当前的步数;
bool vis[N][N];//表示当前行有没有走过
int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };// 上下左右四个方向
PII c[N][N];// 存储上一步

bool check(int x, int y)
{
	return x > 0 && x <= n && y > 0 && y <= m;
}

int bfs()
{
	int hh = 1, tt = 1;// 队头和队尾
	while (hh <= tt)
	{
		auto t = q[hh++];// 出队;

		for (int i = 0; i < 4; i++)
		{
			int x = dir[i][0] + t.first;
			int y = dir[i][1] + t.second;
			if (!vis[x][y] && a[x][y] == 0 && check(x, y))
			{
				b[x][y] = b[t.first][t.second] + 1;
				c[x][y] = t;// 存储上一个位置;
				vis[x][y] = true;
				q[++tt] = { x,y };// 入队
			}
		}
	}
	return b[n][m];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];// 存储数据
		}
	}
	q[1] = { 1,1 };
	vis[1][1] = true;
	int ret = bfs();
	cout << ret << endl;
	// 打印位置
	while (n >= 1 && m >= 1)
	{
		cout << n << " " << m << endl; // 打印N和m的下标
		n = c[n][m].first;
		m = c[n][m].second;
	}
	return 0;
}