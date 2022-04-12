// �������ܷ񵽴��յ�

#include<iostream>
using namespace std;

typedef pair<int, int> PII;
int n, m ;
const int N = 20;
bool vis[N][N];// ��ʾ��ǰ������û���߹�;
int a[N][N];
PII q[N * N];// �����������N��N�и����������������ʾ��
int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };// ��ʾ�ĸ�����
bool flag;

bool check(int x, int y)
{
	return x > 0 && x <= n && y > 0 && y <= m;
}

void bfs()
{
	int hh = 1, tt = 1;
	while (hh <= tt)
	{
		auto t = q[hh++];// ����
		if (t.first == n && t.second == m)
		{
			puts("YES\n");
			flag = true;
			return;
		}


		for (int i = 0; i < 4; i++)
		{
			int x = t.first + dir[i][0];
			int y = t.second + dir[i][1];
			if (!vis[x][y] && a[x][y] == 1 && check(x, y))
			{
				vis[x][y] = true;
				q[++tt] = { x,y };
			}
		}
	}
}

int main()
{
	cin >> n >> m; //n��  m�е�����
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	q[1] = { 1,1 };// �ѳ�ʼλ�ô�������;
	vis[1][1] = true;
	bfs();
	if (!flag)
	{
		puts("NO\n");
	}

	return 0;
}