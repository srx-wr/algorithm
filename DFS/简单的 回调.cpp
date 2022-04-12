#include<iostream>
using namespace std;
int n;

void dfs(int u)
{
	if(u > n)
	{
		return;
	}
	
	dfs(u + 1);
	
	for(int i = 0; i < u; i++)
	{
		printf("%d ", u); 
	}
	printf("\n");
}

int main()
{
	cin >> n;
	dfs(1);
	return 0;
}
