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

int eggdropping(int e, int f)
{
    if(e == 1)
        return f;
    if(f == 0 || f==1)
        return f;
    if(dp[e][f] != -1)
        return dp[e][f];
    int mn = INT_MAX, temp_ans;
    for(int k = 1; k<=f; k++)
    {
        temp_ans = 1+std::max(eggdropping(e-1,f-1), eggdropping(e,f-k));
        mn = std::min(temp_ans, mn);
    }
    return dp[e][f] = mn;
}

int main()
{
    ll t,e,f;
    std::cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        std::cin>>e>>f;
        std::cout<<"Worst Attempt: "<< eggdropping(e,f)<<'\n';
    }
    return 0;
}
