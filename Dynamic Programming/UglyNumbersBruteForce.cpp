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

ll divide(int a, int b)
{
	while(a%b==0)
		a /= b;
	return a;
}

ll isugly(int n)
{
	n = divide(n,2);
	n = divide(n,3);
	n = divide(n,5);
	if(n == 1)
		return 1;
	return 0;
}

ll ugly(int n)
{
	ll i = 1, count = 1;
	while(n > count)
	{
		i++;
		if(isugly(i))
			count++;
	}
	return i;
}

int main()
{
	ll n;
	std::cin>>n;
	std::cout<<ugly(n)<<'\n';
	return 0;
}
