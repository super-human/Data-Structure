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

int mcm(int arr[], int i, int j)
{
    if(i>=j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int mn = INT_MAX, temp_ans;
    for(int k = i; k<j; k++)
    {
        temp_ans = mcm(arr,i,k) + mcm(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        mn = std::min(temp_ans, mn);
    }
    return dp[i][j] = mn;
}

int main()
{
    ll t,n;
    std::cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        std::cin>>n;
        int arr[n];
        for(int i = 0; i<n; i++)
            std::cin>>arr[i];
        std::cout<<"Cost: "<< mcm(arr,1,n-1)<<'\n';
    }
    return 0;
}
