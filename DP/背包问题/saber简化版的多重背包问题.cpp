#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int dp[N];

int n,m;
int v,w,k;
int main()
{
	 cin >> n >> m;
	while(n --)
	{
		cin >> v >> w >> k;
		for(int i = 0; i < k; i++)
		{
			for(int j = m; j >= v; j--)
			{
				dp[j] = max(dp[j],dp[j - v] + w);
			}
		}
	}
	printf("%d",dp[m]);
	return 0;
 } 
