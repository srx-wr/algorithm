#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1010;
int dp[N][N],v[N],w[N];
int n,m;
int main()
{
	cin >> n >> m;
	for(int i = 1; i < n; i++) cin >> v[i] >> w[i];
	
	for(int i = 1; i < n; i++) // �������е���Ʒ 
	{
		for(int j = 0; j <= m; j++) //���������������Ŀ����� 
		 {
		 	for(int k = 0; k * v[i] <= j; k++)
			{
			 	dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
			}
		 }
	}
	cout << dp[n - 1][m];
	
	return 0;
} 	
