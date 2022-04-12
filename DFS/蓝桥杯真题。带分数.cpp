/*
	���ű�����  ������
*/

#include<iostream>
#include<cstring>
using namespace std;

const int N = 20;
bool had_use[N], tmp[N]; // tmpΪ��ʱ������had_use��ʾ ��ǰ����û�б�ʹ��
int ans = 0; // ������
int n;
bool check(int a, int c)
{
	int b = n * c - a * c;
	if (!a || !b || !c) return false;
	memcpy(tmp, had_use, sizeof had_use); // ��Ϊ����Ҫ�ı�����  ������Ҫ��ʱ����һ�£�

	while (b)
	{
		int t = b % 10;
		b /= 10;
		if (!t || tmp[t]) return false; // t��Ϊ�㲢�ң�t֮ǰû�г��ֹ�
		tmp[t] = 1;
	}
	for (int i = 1; i <= 9; i++)
	{
		if (!tmp[i])
		{
			return false;
		}
	}
	return true;

}

void dfs_c(int x, int a, int c)
{
	if (x >= 10) return;
	if (check(a, c)) ans++;
	for (int i = 1; i <= 9; i++)
	{
		if (!had_use[i])
		{
			had_use[i] = true;
			dfs_c(x + 1, a, c * 10 + i);
			had_use[i] = false;
		}
	}
}

void dfs_a(int x, int a)
{
	if (a >= n) return;// ��ʾa �Ĵ�СԽ���ˣ�
	if (a) dfs_c(x, a, 0); // a��Ϊ��͵ݹ������һ��

	for (int i = 1; i <= 9; ++i)
	{
		if (!had_use[i])
		{
			had_use[i] = true;
			dfs_a(x + 1, a * 10 + i);
			had_use[i] = false;
		}
	}
}

int main()
{
	cin >> n;
	dfs_a(0, 0);  //��һ��0 ��ʾ�Ѿ�ʹ���˶��ٸ�����  �����o ��ʾa������
	cout << ans << endl;
	return 0;
}