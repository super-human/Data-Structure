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

int t[1001][1001];

bool SubsetSum(int arr[], int sum, int n)
{
    if(sum == 0)
        return 1;
    else if(n == 0 && sum != 0)
        return 0;
    if(t[n][sum] != -1)
        return t[n][sum];
    if(arr[n-1]<=sum)
     return t[n][sum] = (SubsetSum(arr,sum-arr[n-1],n-1)|| SubsetSum(arr,sum,n-1));
    else if(arr[n-1]>sum)
     return t[n][sum] = SubsetSum(arr,sum,n-1);

}

int main()
{
    memset(t,-1,sizeof(t));
    ll t,n,sum;
    std::string s;
    std::cin>>t;
    while(t--)
    {
    	std::cin>>n>>sum;
        int arr[n];
        for(int i = 0; i<n; i++)
            std::cin>>arr[i];
        if(SubsetSum(arr,sum,n))
            std::cout<<"True"<<'\n';
        else
            std::cout<<"False"<<'\n';
    }
    return 0;
}