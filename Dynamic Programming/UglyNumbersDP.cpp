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
#define mod 1000000007



int main()
{
	ll t,n;
	std::cin>>t;
	ll ugly[10001],i2 = 0, i3 = 0, i5 = 0;
	ll num2 = 2, num3 = 3, num5 = 5;
	ugly[0] = 1;
	for(ll i = 1; i<=10000; i++)
	{
		ugly[i] = std::min({num2,num3,num5});
		if(ugly[i] == num2)
			num2 = ugly[++i2] * 2;
		if(ugly[i] == num3)
			num3 = ugly[++i3]*3;
		if(ugly[i] == num5)
			num5 = ugly[++i5]*5;
	}
	while(t--)
	{
		std::cin>>n;
		std::cout<<ugly[n-1]<<'\n';
	}
	return 0;
}
