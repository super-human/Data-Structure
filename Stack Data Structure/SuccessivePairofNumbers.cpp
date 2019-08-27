#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>


int main(int argc, char const *argv[])
{
	int flag = 0;
	std::queue<int> q;
	std::stack<int> s;
	s.push(4);
	s.push(5);
	s.push(-2);
	s.push(-3);
	s.push(11);
	s.push(10);
	s.push(5);
	s.push(6);
	s.push(20);
	if(s.size()%2==1)
		s.pop();
	int temp = s.top();
	s.pop();
	while(!s.empty())
	{
		if(abs(temp - s.top()) != 1)
		{
			flag = 1;
			break;
		}
		s.pop();
		if(!s.empty())
		{
			temp = s.top();
			s.pop();
		}
		
	}
	if(flag == 1)
		std::cout<<"All pairs are not successive "<<std::endl;
	else
		std::cout<<"All pairs are successive "<<std::endl;
	return 0;
}
