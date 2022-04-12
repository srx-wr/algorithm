#include<iostream>
#include<algorithm> 
using namespace std;

const int N = 1010;
int n,m;
int dp[N],v[N],w[N];

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> v[i] >> w[i];
	
	for(int i = 0; i < n; i++)
	{
		// 这里为什么要用倒叙呢？看完代码我会再后文中解释 
		for(int j = m; j >= v[i]; j--)
		{
			// 这里不用判断的原因是因为放不开就不放了嘛。 
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);	
		}
	}
	
	printf("%d",dp[m]);
	
	return 0;
}

