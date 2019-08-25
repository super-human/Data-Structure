#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>

//Refer to https://stackoverflow.com/a/35931960/8687412 for proper understanding

int main(int argc, char const *argv[])
{
	int num,i,area = 0,area_h,top;
	std::cin>>num;
	std::stack<int> s;
	int h[num];
	for(int i = 0; i<num;i++)
		std::cin>>h[i];
	i=0;
	while(i<num)
	{
		if(s.empty() || h[s.top()] <= h[i])
			s.push(i++);
		else			//stack[x-1] is the first smaller on the left on stack[x]
		{
			top = s.top();
			s.pop();
			area_h = h[top]* (s.empty() ? i : i - s.top() - 1);
			if(area < area_h)
				area=area_h;
		}
	}
	while(!s.empty())
	{
		top = s.top();
		s.pop();
		area_h = h[top]* (s.empty() ? i : i - s.top() - 1);
		if(area < area_h)
				area=area_h;
	}

	std::cout<<area<<'\n';
	return 0;
}
