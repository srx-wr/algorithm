#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;
int n,m;
// v[i] 存储 物品的体积，w[i] 存储物品的价值 
int v[N],w[N];
int res;
// u表示第u个物品 sum 表示背包内已经存放物品的体积
 
void dfs(int u,int sumv,int sumw)
{
	// 如果 第u 个物品已经超过或者等于 n个了，注：这里不会超过只会等于，超过只是个人习惯，怕出错。当等于n个的时候，
	// 我们判断 背包中所有物品的体积是不是 能够放入背包，如果可以放入那么刷新 res 结果.w 
	if(u >= n)
	{
		if(sumv <= m)
		{
			res = max(res,sumw);
		}
		return;
	}
	// 如果 物品的体积 大于等于 背包的容量时 我们判断 如果等于就刷新res 
	if(sumv >= m)
	{
		if(sumv == m)
		{
			res = max(res,sumw);
		}
		return;
	}
	
	// 选当前物品
	dfs(u + 1,sumv + v[u],sumw + w[u]);
	// 不选择当前物品
	dfs(u + 1,sumv,sumw); 
	 
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> v[i] >> w[i];
	dfs(0,0,0);
	cout << res << endl;
	return 0;
}
