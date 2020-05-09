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

int lcs(std::string X, std::string Y, int n, int m)
{
    if(n == 0 || m == 0)
        return 0;
    if(dp[n][m] != -1)
        return dp[n][m];
    if(X[n-1] == Y[m-1])
        return dp[n][m] = 1 + lcs(X,Y,n-1,m-1);
    else
        return dp[n][m] = std::max(lcs(X,Y,n-1,m), lcs(X,Y,n,m-1));
}

int main()
{
    int testcases,n;
    std::cin>>testcases;
    while(testcases--)
    {
        std::memset(dp,-1,sizeof(dp));
        std::string x, y;
        std::cin>>x>>y;
        std::cout<<lcs(x,y,x.size(),y.size())<<'\n';
    }
    return 0;
}
