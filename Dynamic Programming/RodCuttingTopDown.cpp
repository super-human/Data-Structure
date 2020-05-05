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

int rodcutting(int length[], int price[], int len, int n)
{
    if(n == 0 || len == 0)
        return 0;
    if(t[n][len] != -1)
        return t[n][len];
    if(length[n-1] <= len)
        return t[n][len] = std::max(price[n-1] + rodcutting(length, price, len-length[n-1], n), rodcutting(length, price, len, n-1));
    else if(length[n-1] > len)
        return t[n][len] = rodcutting(length, price, len, n-1);
}

int main()
{
    int testcases,n,len;
    std::cin>>testcases;
    while(testcases--)
    {
        memset(t,-1,sizeof(t));
        std::cin>>n;  
        int length[n], price[n];
        for(int i = 0; i<n; i++)
            std::cin>>length[i];
        for(int i = 0; i<n; i++)
            std::cin>>price[i];
        std::cin>>len;
        std::cout<<rodcutting(length,price,len,n)<<'\n';

    }
    return 0;
}
