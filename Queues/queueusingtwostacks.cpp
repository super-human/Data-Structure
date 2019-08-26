#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>

// https://www.geeksforgeeks.org/reversing-a-queue/

std::stack<int> s1;
std::stack<int> s2;

void enqueue(int x)
{
	s1.push(x);
}

int dequue()
{
	int x = -1;
	if(!s1.empty())
	{
		if(!s2.empty())
		{
			x = s2.top();
			s2.pop();
		}
		else
		{
			while(!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
			x = s2.top();
			s2.pop();
		}
	}
	return x;
}

int main(int argc, char const *argv[])
{
	enqueue(3);
	enqueue(5);
	enqueue(2);
	enqueue(7);
	std::cout<<dequue()<<" ";
	enqueue(9);
	enqueue(8);
	enqueue(4);
	std::cout<<dequue()<<" ";
	return 0;
}
