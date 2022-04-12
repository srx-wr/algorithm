#include<iostream>
#include<algorithm>
using namespace std;

typedef pair<int, int> PII;
const int N = 110;

int n, m;
int g[N][N];// �洢ͼ
int d[N][N];// �洢����
PII q[N * N];//ģ��ʵ�ֶ��� N* N ��ʾ���洢��Ԫ��
// q.first ��ʾx�����꣬ q.second ��ʾy�������
int bfs()
{
	int hh = 0, tt = 0; // ��ͷ�Ͷ�β Ĭ��Ϊ0
	q[0] = { 0,0 };// �ֱ��first ��secent ��ֵΪ0��
	memset(d, -1, sizeof d);// ��dȫ����ֵΪ-1;
	d[0][0] = 0;
	int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };// ��ʾ�ĸ�����
	while (hh <= tt)
	{
		auto t = q[hh++]; // ȡ����ͷԪ��
		for (int i = 0; i < 4; i++)// �����ĸ�����
		{
			int x = t.first + dir[i][0];
			int y = t.second + dir[i][1];
			if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
			{
				d[x][y] = d[t.first][t.second] + 1;
				q[++tt] = { x,y }; //  ����ʼλ�õ��ĸ������кϷ��ĵ�λ�����
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