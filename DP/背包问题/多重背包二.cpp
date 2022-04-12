#include<iostream>
using namespace std;

const int N1 = 2010;
const int N2 = 20100;
int dp[N1];
int v[N2],w[N2];
int v1,m,w1,s,n,t; 

int main()
{
	cin >> n >> m;
	while(n --)
	{
		cin >> v1 >> w1  >> s;
		// 二维转换
		for(int i = 1; i <= s; i *= 2)
		{
			s -= i;
			v[t] = v1*i;
			w[t] = w1*i;
			t++;
		 }
		if(s > 0)
		{
			v[t] = s * v1;
			w[t] = w1 * s;
			t ++;
		}
	}
	// 套用01背包模板
	for(int i = 0; i < t; i++)
	{
		for(int j = m; j >=v[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
		}
	 }
	 cout << dp[m] << endl;
	
	return 0;
}
