/*
	蓝桥杯真题  带分数
*/

#include<iostream>
#include<cstring>
using namespace std;

const int N = 20;
bool had_use[N], tmp[N]; // tmp为临时变量，had_use表示 当前数有没有被使用
int ans = 0; // 方案数
int n;
bool check(int a, int c)
{
	int b = n * c - a * c;
	if (!a || !b || !c) return false;
	memcpy(tmp, had_use, sizeof had_use); // 因为后面要改变数据  所以需要临时拷贝一下；

	while (b)
	{
		int t = b % 10;
		b /= 10;
		if (!t || tmp[t]) return false; // t不为零并且，t之前没有出现过
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
	if (a >= n) return;// 表示a 的大小越界了；
	if (a) dfs_c(x, a, 0); // a不为零就递归进入下一层

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
	dfs_a(0, 0);  //第一个0 表示已经使用了多少个数据  后面的o 表示a的数据
	cout << ans << endl;
	return 0;
}