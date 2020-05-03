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

int Knapsack(int val[], int weight[], int w, int n)
{
    if(n == 0 || w == 0)
        return 0;
    if(t[n][w] != -1)
        return t[n][w];
    if(weight[n-1]<=w)
     return t[n][w] = std::max(val[n-1]+Knapsack(val,weight,w-weight[n-1],n-1), Knapsack(val,weight,w,n-1));
    else if(weight[n-1]>w)
     return t[n][w] = Knapsack(val,weight,w,n-1);

}

int main()
{
    memset(t,-1,sizeof(t));
    ll t,n,w;
    std::string s;
    std::cin>>t;
    while(t--)
    {
        std::cin>>n>>w;
        int val[n], weight[n];
        for(int i = 0; i<n; i++)
            std::cin>>val[i];
        for(int i = 0; i<n; i++)
            std::cin>>weight[i];
        std::cout<<Knapsack(val,weight,w,n)<<'\n';
    }
    return 0;
}