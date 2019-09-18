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

//Count ways to reach the n’th stair using 3 steps

int s[100];
ll stair(ll n)
{
	if(n == 0 || n == 1)
		return 1;
	if(n == 2)
		return 2;
	if(s[n] != -1)
		return s[n];
	s[n] = stair(n-1) + stair(n-2) + stair(n-3);
	return s[n];
}

/*ll stair(ll n)
{
	int s[n+1];
	s[0] = 1;
	s[1] = 1;
	s[2] = 2;
	for(ll i = 3; i <= n; i++)
		s[i] = s[i-1]+s[i-2]+s[i-3];
	return s[n];
}*/

int main()
{
	ll t,n;
	std::cin>>t;
	while(t--)
	{
		std::cin>>n;
		std::memset(s,-1,sizeof(s));
		std::cout<<stair(n)<<'\n';
	}
	return 0;
}
