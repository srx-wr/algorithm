#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;
int n, m;
int dp[N][N],v[N],w[N];


int main()
{
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) cin >> v[i] >> w[i];
	// 初始化 我们这里定义的是全局变量已经默认为0 不需要初始化了就  我们便于理解所以初始化 
	for(int i = 0; i < n; i++) dp[0][i] = dp[i][0] = 0; 
	
	for(int i = 0; i < n ;i ++)
	{
		for(int j = 0; j <= m; j++)
		{
			if(j < v[i])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - v[i]]+w[i]);
			}
		}
	 }
	 int res = dp[n - 1][m];
	 // 这里要特别说明一下，最右下角必然是 最大值，
    cout << res << endl; 
	return 0;
}
