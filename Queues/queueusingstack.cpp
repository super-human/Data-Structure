#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
	stack<int> s1,s2;
	void enqueue(int);
	int dequeue();
};

void Queue::enqueue(int x)
{
	s1.push(x);
}

int Queue::dequeue()
{
	int x = -1;
	if(s1.empty() && s2.empty())
	{
		cout<<"Queue is empty"<<endl;
		return -1;
	}
	if(s2.empty())
	{
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}
	x = s2.top();
	s2.pop();
	return x;
}

int main(int argc, char const *argv[])
{
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	return 0;
}
