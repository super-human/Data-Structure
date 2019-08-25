#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>

// Linear Time Complexity Method with the help of Stack

int main(int argc, char const *argv[])
{
	int n,j;
	std::cin>>n;
	int price[n];
	int stockArray[n];
	std::stack<int> s;
	for (int i = 0; i < n; ++i)
		std::cin>>price[i];
	s.push(0);
	stockArray[0] = 1;
	for (int i = 1; i < n; ++i)
	{
		while(!s.empty() && price[s.top()] <= price[i])
			s.pop();
		stockArray[i] = (s.empty()) ? i+1 : i-s.top();
		s.push(i);
	}

	for (int i = 0; i < n; ++i)
		std::cout<<stockArray[i]<<" ";
	std::cout<<'\n';
	return 0;
}
