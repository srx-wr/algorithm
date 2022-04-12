#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;
int n,m;
int dp[N],v[N],w[N]; 

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i ++) cin >> v[i] >> w[i];
	for(int i = 0; i < n; i ++)
	{
		for(int j = v[i]; j <= m; j ++)
		{
			dp[j] = max(dp[j],dp[j - v[i]] + w[i]);
		}
	}
	printf("%d",dp[m]);
	
	return 0;
 } 
