#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e6+10;
int q[N],a[N];
int n,k;


int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++) scanf("%d",&a[i]);
	int hh = 0,tt = -1;
	for(int i = 0; i < n; i++)
	{
		if(hh <= tt && q[hh] < i - k + 1) hh ++;
		while(hh <= tt && a[q[tt]] >= a[i]) tt--;
		q[++tt] = i;
		if(i >= k - 1) printf("%d ",a[q[hh]]);
	}
	printf("\n");
	hh = 0,tt = -1;
	for(int i = 0; i < n; i++)
	{
		if(hh <= tt && q[hh] < i - k + 1) hh ++;
		while(hh <= tt && a[q[tt]] <= a[i]) tt--;
		q[++tt] = i;
		if(i >= k - 1) printf("%d ",a[q[hh]]);
	}
	printf("\n");
	return 0;
}
