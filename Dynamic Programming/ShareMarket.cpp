#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>

int sharemarket(int price[], int n)
{
	int min_uptil[n],max_profit[n];
	min_uptil[0] = price[0];
	int highest_profit = INT_MIN;
	for (int i = 1; i < n; ++i)
		min_uptil[i] = std::min(price[i],min_uptil[i-1]);
	for (int i = 0; i < n; ++i)
	{
		max_profit[i] = price[i] - min_uptil[i];
		if(highest_profit < max_profit[i])
			highest_profit = max_profit[i];
	}
	return highest_profit;
}

int main()
{
	int n;
	std::cin>>n;
	int price[n];
	for (int i = 0; i < n; ++i)
		std::cin>>price[i];
	int sz = sizeof(price)/sizeof(price[0]);
	std::cout<<sharemarket(price,sz)<<'\n';
	return 0;
}
