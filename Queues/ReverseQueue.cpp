#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>

// Reverse a queue

std::queue<int> reverse(std::queue<int>& q)
{
	std::stack<int> s;
	while(!q.empty())
	{
		s.push(q.front());
		q.pop();
	}
	while(!s.empty())
	{
		q.push(s.top());
		s.pop();
	}
	return q;
}

int main(int argc, char const *argv[])
{
	std::queue<int> q;
	q.push(3);
	q.push(5);
	q.push(7);
	q.push(9);
	q = reverse(q);
	while(!q.empty())
	{
		std::cout<<q.front()<<" ";
		q.pop();
	}
	std::cout<<'\n';
	return 0;
}
