#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>

void interLeaveQueue(std::queue<int>& q)
{
	std::stack<int> s;
	if(q.size()%2 != 0)
		return;
	int halfsize = q.size()/2;
	for (int i = 0; i < halfsize; ++i)
	{
		s.push(q.front());
		q.pop();
	}

	for (int i = 0; i < halfsize; ++i)
	{
		q.push(s.top());
		s.pop();
	}
	for (int i = 0; i < halfsize; ++i)
	{
		q.push(q.front());
		q.pop();
	}
	for (int i = 0; i < halfsize; ++i)
	{
		s.push(q.front());
		q.pop();
	}

	while(!s.empty())
	{
		q.push(s.top());
		s.pop();
		q.push(q.front());
		q.pop();
	}
}

int main(int argc, char const *argv[])
{
	std::queue<int> q;
	
	q.push(11); 
    q.push(12); 
    q.push(13); 
    q.push(14); 
    q.push(15); 
    q.push(16); 
    q.push(17); 
    q.push(18); 
    q.push(19); 
    q.push(20); 
    interLeaveQueue(q); 
    int length = q.size();
    for (int i = 0; i < length; ++i)
    {
    	std::cout<<q.front()<<" ";
    	q.pop();
    }
    std::cout<<'\n';
	return 0;
}
