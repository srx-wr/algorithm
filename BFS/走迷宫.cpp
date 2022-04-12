#include<iostream>
#include<algorithm>
using namespace std;

typedef pair<int, int> PII;
const int N = 110;

int n, m;
int g[N][N];// 存储图
int d[N][N];// 存储距离
PII q[N * N];//模拟实现队列 N* N 表示最多存储的元素
// q.first 表示x的坐标， q.second 表示y点的坐标
int bfs()
{
	int hh = 0, tt = 0; // 队头和队尾 默认为0
	q[0] = { 0,0 };// 分别给first 和secent 赋值为0；
	memset(d, -1, sizeof d);// 给d全部赋值为-1;
	d[0][0] = 0;
	int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };// 表示四个方向
	while (hh <= tt)
	{
		auto t = q[hh++]; // 取出队头元素
		for (int i = 0; i < 4; i++)// 遍历四个方向
		{
			int x = t.first + dir[i][0];
			int y = t.second + dir[i][1];
			if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
			{
				d[x][y] = d[t.first][t.second] + 1;
				q[++tt] = { x,y }; //  将初始位置的四个方向中合法的单位都入队
			}
		}
	}
	return d[n - 1][m - 1];
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> g[i][j];
		}
	}
	cout << bfs() << endl;

	return 0;
}