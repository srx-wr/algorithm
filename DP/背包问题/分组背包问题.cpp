#include<iostream>
#include<algorithm> 
using namespace std;
const int N = 110;
int dp[N],v[N][N],w[N][N];
int s[N]; // s�洢��ǰ�����ж��ٸ�Ԫ�� 
int n,m;

int main()
{
	cin >> n >> m; 
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		for(int j = 1; j <= s[i]; j++)
		{
			scanf("%d%d",&v[i][j],&w[i][j]); // i j ��ʾ��i ���j���� 
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = m; j >= 0; j--)
		{
			for(int k = 1; k <= s[i]; k++)
			{
				if(j >= v[i][k])
				dp[j] = max(dp[j],dp[j - v[i][k]] + w[i][k]);
			}
		}
	 }
	 printf("%d",dp[m]);
	
	return 0;
 } 
