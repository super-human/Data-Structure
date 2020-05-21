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

int lcs(std::string s1, std::string s2, int m, int n)
{
    if( m == 0 || n == 0)
        return 0;
    if(dp[m][n] != -1)
        return dp[m][n];
    if(s1[m-1] == s2[n-1])
        return dp[m][n] = 1+lcs(s1,s2,m-1,n-1);
    else
        return dp[m][n] = std::max(lcs(s1,s2,m-1,n), lcs(s1,s2,m,n-1));
}

int main()
{
    ll t,n,sum;
    std::string s1, s2;
    std::cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        std::cin>>s1>>s2;
        int x = lcs(s1,s2,s1.length(), s2.length());
        int i = s1.length(), j = s2.length();
        std::string s = "";
        while(i>0 && j> 0)
        {
            if(s1[i-1] == s2[j-1])
            {
                s.push_back(s1[i-1]);
                i--;
                j--;
            }
            else
            {
                if(dp[i][j-1] > dp[i-1][j])
                    j--;
                else
                    i--;
            }
        }
        std::reverse(s.begin(), s.end());
        std::cout<<x<<'\n';
        std::cout<<s<<'\n';
    }
    return 0;
}
