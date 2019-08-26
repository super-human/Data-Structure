#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>

// Implementation of queue using a single function call

std::stack<int> s;

void enqueue(int x)
{
	s.push(x);
}

int dequeue()
{
	if(s.empty())
	{
		std::cout<<"Queue is empty"<<std::endl;
		exit(0);
	}
	int t = s.top();
	s.pop();
	if(s.empty())
		return t;
	int item = dequeue();
	s.push(t);
	return item;
}

bool isEmpty()
{
	return (s.empty() ? true : false);
}

int main(int argc, char const *argv[])
{
	enqueue(3);
	enqueue(5);
	enqueue(2);
	enqueue(7);
	std::cout<<dequeue()<<" ";
	enqueue(9);
	enqueue(8);
	enqueue(4);
	std::cout<<dequeue()<<" ";
	std::cout<<'\n';
	while(!isEmpty())
	{
		std::cout<<dequeue()<<" ";
	}
	return 0;
}
