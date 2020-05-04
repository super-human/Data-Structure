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


int main()
{
    
    int testcases,n,sum,diff;
    std::cin>>testcases;
    while(testcases--)
    {
        sum = 0;
        std::cin>>n>>diff;
        int arr[n];
        for(int i = 0; i<n; i++)
        {
            std::cin>>arr[i];
            sum += arr[i];
        }
        t[0][0] = 1;
        for(int i=0; i<=n; i++)
        {
            for(int j = 0; j<=sum; j++)
            {
                if(i == 0)
                    t[i][j] = 0;
                if(j == 0)
                    t[i][j] = 1;
            }
                
        }
        int s1 = (diff+sum)/2;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j<= s1; j++)
                if(arr[i-1]<=j)
                    t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
        std::cout<<t[n][s1]<<'\n';
    }
    return 0;
}
