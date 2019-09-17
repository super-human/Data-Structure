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



ll fib(ll n)
{
	int f[n+1]; //1 extra space to handle index 0
	f[0]=0;
	f[1] = 1;
	for(int i = 2; i<=n;i++)
		f[i] = (f[i-1]+f[i-2])%1000000007;
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
		std::cout<<fib(n)<<'\n';
	}
	return 0;
}
