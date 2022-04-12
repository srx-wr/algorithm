#include<iostream>
using namespace std;
typedef pair<int, int> PII;
const int N = 20;
int n, m;// n�� m��
PII q[N * N];
int a[N][N];
int b[N][N];//��ʾ��ǰ�Ĳ���;
bool vis[N][N];//��ʾ��ǰ����û���߹�
int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };// ���������ĸ�����
PII c[N][N];// �洢��һ��

bool check(int x, int y)
{
	return x > 0 && x <= n && y > 0 && y <= m;
}

int bfs()
{
	int hh = 1, tt = 1;// ��ͷ�Ͷ�β
	while (hh <= tt)
	{
		auto t = q[hh++];// ����;

		for (int i = 0; i < 4; i++)
		{
			int x = dir[i][0] + t.first;
			int y = dir[i][1] + t.second;
			if (!vis[x][y] && a[x][y] == 0 && check(x, y))
			{
				b[x][y] = b[t.first][t.second] + 1;
				c[x][y] = t;// �洢��һ��λ��;
				vis[x][y] = true;
				q[++tt] = { x,y };// ���
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
			cin >> a[i][j];// �洢����
		}
	}
	q[1] = { 1,1 };
	vis[1][1] = true;
	int ret = bfs();
	cout << ret << endl;
	// ��ӡλ��
	while (n >= 1 && m >= 1)
	{
		cout << n << " " << m << endl; // ��ӡN��m���±�
		n = c[n][m].first;
		m = c[n][m].second;
	}
	return 0;
}