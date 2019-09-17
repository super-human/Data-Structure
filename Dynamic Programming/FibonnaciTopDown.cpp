#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
#include<stack>
#include<queue>
#include<cstring>
#include<cmath>
#define ll long long

int f[1001];

ll fib(ll n)
{
	if(n == 0 || n == 1)
		return n;
	if(f[n] != -1)
		return f[n];
	f[n] = (fib(n-1) + fib(n-2))%1000000007;
	return f[n];
}

int main()
{
	ll t,n;
	std::cin>>t;
	while(t--)
	{
		ll n;
		std::cin>>n;
		memset(f,-1,sizeof(f));
		std::cout<<fib(n)<<'\n';
	}
	return 0;
}
