#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<map>
#define ll long long
#define ld long double
#define mod 1000000007
#define pb push_back
#define N 100001

int dp[1001][1001];
int ans = 0;
int LongestCommonSubstring(std::string X, std::string Y, int m, int n)
{
	if(n == 0 || m == 0)
		return 0;
	if(dp[m][n] != -1)
		return dp[m][n];
	LongestCommonSubstring(X, Y, n-1, m);	//to visit all n*m states		(try example:  X:ASDF Y:ASDFF)
	LongestCommonSubstring(X, Y, n, m-1);	// we call these states first
	if(X[m-1] == Y[n-1])
	{
		dp[m][n] = 1 + LongestCommonSubstring(X, Y, m-1, n-1);
		ans = std::max(ans, dp[m][n]);
		return dp[m][n];
	}
	else
		return dp[m][n] = 0;
}

int main()
{
	int testcases;
	std::cin>>testcases;
	while(testcases--)
	{
		std::memset(dp,-1,sizeof(dp));
		std::string X, Y;
		std::cin>>X>>Y;
		LongestCommonSubstring(X, Y, X.size(), Y.size());
		std::cout<<ans<<'\n';
	}
	return 0;
}