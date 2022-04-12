#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
using namespace std;

#define Inf 0x3f3f3f
const int N = 10;
int a[N][N];
int b[N][N];
int ans = 0x3f3f3f;
int check(int cnt)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			b[i][j] = a[i][j];// ����
		}
	}
	for (int i = 1; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (!b[i - 1][j])// �����һ�еĵƿ��� ,��ô��һ�еĵƾͱ�����һ��
			{
				cnt++;
				b[i - 1][j] = !b[i - 1][j]; //��һ�е��м�
				if (j > 0) b[i][j - 1] = !b[i][j - 1]; // ��ǰ�е����
				if (j < 4)  b[i][j + 1] = !b[i][j + 1];// ��ǰ�е��ұ�
				b[i + 1][j] = !b[i + 1][j]; // ��һ�е��м�
				b[i][j] = !b[i][j]; // ��ǰҪ��������
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (b[4][i] == 0)
		{
			return Inf;
		}
	}
	return cnt;

}
void dfs(int u,int k)
{
	if (u == 5)
	{
		ans = min(ans, check(k));
		return;
	}

	// ���� 
	dfs(u + 1, k);

	//��
	a[0][u] = !a[0][u];
	if (u - 1 >= 0)
		a[0][u - 1] = !a[0][u - 1];
	if (u + 1 < 5)
		a[0][u + 1] = !a[0][u + 1];
	a[1][u] = !a[1][u];
	dfs(u + 1, k + 1);
	// ״̬�ָ�
	a[0][u] = !a[0][u];
	if (u - 1 >= 0)
		a[0][u - 1] = !a[0][u - 1];
	if (u + 1 < 5)
		a[0][u + 1] = !a[0][u + 1];
	a[1][u] = !a[1][u];
}

int main()
{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		dfs(0,0);
		if (ans < 8) cout << ans << endl;
		else cout << -1 << endl;
	return 0;
}