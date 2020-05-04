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

bool t[1001][1001];


int main()
{
    
    int testcases,n,sum;
    std::cin>>testcases;
    while(testcases--)
    {
        sum = 0;
        std::cin>>n;
        int arr[n];
        for(int i = 0; i<n; i++)
        {
            std::cin>>arr[i];
            sum += arr[i];
        }
        t[0][0] = true;
        for(int i=0; i<=n; i++)
        {
            for(int j = 0; j<=sum; j++)
            {
                if(i == 0)
                    t[i][j] = false;
                if(j == 0)
                    t[i][j] = true;
            }
                
        }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j<= sum; j++)
                if(arr[i-1]<=j)
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
        std::vector<int> v;
        int min = INT_MAX;
        for(int i = 0; i<=sum/2; i++)
            if(t[n][i] == true)
                v.pb(i);
        for(int i = 0; i<v.size(); i++)
            min = std::min(min, sum - 2*v[i]);
        std::cout<<min<<'\n';
    }
    return 0;
}
