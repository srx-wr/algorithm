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
	// ��ʼ�� �������ﶨ�����ȫ�ֱ����Ѿ�Ĭ��Ϊ0 ����Ҫ��ʼ���˾�  ���Ǳ���������Գ�ʼ�� 
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
	 // ����Ҫ�ر�˵��һ�£������½Ǳ�Ȼ�� ���ֵ��
    cout << res << endl; 
	return 0;
}
