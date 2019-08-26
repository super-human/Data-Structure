#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
#include<cstring>

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;		//no of elements
	std::stack<int> s;
	int arr[n];			// array to hold elements
	for (int i = 0; i < n; ++i)
		std::cin>>arr[i];
	int ans[n],i=0;
	memset(ans,-1,sizeof(ans));		//initializing result array with -1
	while(i<n)
	{
		if(s.empty() || arr[s.top()]>arr[i])		//push till incoming element is less than value at top 
			s.push(i++);
		else
		{
			ans[s.top()] = arr[i];
			s.pop();				//pop till incoming element is greater
		}
	}
	for (int i = 0; i < n; ++i)
		std::cout<<ans[i]<<" ";		//-1 in the answer means element does not have  any greater element to its right
	return 0;
}
