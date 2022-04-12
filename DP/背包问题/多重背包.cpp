#include<iostream>
using namespace std;
const int N = 1010;
int n,m;
int v1,w1,k; 
int v[N],w[N],dp[N];
int t;

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		// 暴力展开 
		cin >> v1 >> w1 >> k;
		while(k --)
		{
			v[t] = v1;
			w[t ++] = w1;
		}
	}
	// 套用01 背包的思路
	for(int i = 0; i < m; i++) //遍历物品 
	{
		for(int j = m; j >= v[i]; j --) // 遍历背包容量 
		{
			dp[j] = max(dp[j],dp[j - v[i]] + w[i]); 
		}
	 }
	cout << dp[m] << endl;
	
	return 0;
}
