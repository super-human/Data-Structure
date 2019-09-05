#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>


int rodcutting(int cost[], int lengthOfRod)
{
	int rod[lengthOfRod+1];
	rod[0] = 0;
	for(int i = 1; i<=lengthOfRod; ++i)
	{
		int Max_Val = INT_MIN;
		for(int j = 1; j <= i; ++j)
			Max_Val = std::max(Max_Val, cost[j] + rod[i-j]);
		rod[i]=Max_Val;
	}
	return rod[lengthOfRod];
}

int main()
{
	int cost[5];
	for (int i = 0; i < 5; ++i)
		std::cin>>cost[i];
	int n = sizeof(cost)/sizeof(cost[0]) - 1;	// n is always 1 less than cost array length because 0'th element is cost[0]
	std::cout<<rodcutting(cost,n)<<'\n';
	return 0;
}
