#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;
int n,m;
// v[i] �洢 ��Ʒ�������w[i] �洢��Ʒ�ļ�ֵ 
int v[N],w[N];
int res;
// u��ʾ��u����Ʒ sum ��ʾ�������Ѿ������Ʒ�����
 
void dfs(int u,int sumv,int sumw)
{
	// ��� ��u ����Ʒ�Ѿ��������ߵ��� n���ˣ�ע�����ﲻ�ᳬ��ֻ����ڣ�����ֻ�Ǹ���ϰ�ߣ��³���������n����ʱ��
	// �����ж� ������������Ʒ������ǲ��� �ܹ����뱳����������Է�����ôˢ�� res ���.w 
	if(u >= n)
	{
		if(sumv <= m)
		{
			res = max(res,sumw);
		}
		return;
	}
	// ��� ��Ʒ����� ���ڵ��� ����������ʱ �����ж� ������ھ�ˢ��res 
	if(sumv >= m)
	{
		if(sumv == m)
		{
			res = max(res,sumw);
		}
		return;
	}
	
	// ѡ��ǰ��Ʒ
	dfs(u + 1,sumv + v[u],sumw + w[u]);
	// ��ѡ��ǰ��Ʒ
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
