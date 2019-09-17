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

//Problem : Count ways to Nth Stair (Order doesn't matter)

/*ll stair(ll n)
{
	int sp[m+1];
	sp[0] = 1;
	sp[1] = 1;
	for(ll i = 2; i<=n; i++)
		sp[i] = sp[i-2]+1;
	return sp[n];
} */

ll stair(ll n)
{
	return (n/2)+1;
}


int main()
{
	ll t,n;
	std::cin>>t;
	while(t--)
	{
		std::cin>>n;
		std::cout<<stair(n)<<'\n';
	}
	return 0;
}
