#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>

int OntheWay(int n, int m)
{
	int ways[n][m];
	for (int i = 0; i < n; ++i)
		ways[i][m-1]=1;
	for (int i = 0; i < m; ++i)
		ways[n-1][i] = 1;
	for(int i = n-2; i>=0 ; --i)
		for(int j = m-2; j >= 0; --j)
			ways[i][j] = ways[i+1][j] + ways[i][j+1];
	return ways[0][0];
}

int main() 
{
	int n,m;
	std::cin>>n>>m;
	std::cout<<OntheWay(n,m)<<'\n';
	return 0;
}
