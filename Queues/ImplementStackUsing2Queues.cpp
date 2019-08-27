#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>

#include<queue>
#include<cstring>

// Reverse a queue

std::queue<int> q1;
std::queue<int> q2;
int curr_size = 0;
void push(int x)
{
	q1.push(x);
	curr_size++;
}

int pop()
{
	int x = -1;
	if(q1.empty())
		return x;
	while(q1.size() != 1)
	{
		q2.push(q1.front());
		q1.pop();
	}
	x = q1.front();
	q1.pop();
	curr_size--;
	// swap the names of two queues 
        std::queue<int> q = q1; 
        q1 = q2; 
        q2 = q; 
    return x;
}

int top()
{
	if(q1.empty())
		return -1;
	while(q1.size() != 1)
	{
		q2.push(q1.front());
		q1.pop();
	}
	int t = q1.front();
	q1.pop();
	q2.push(t);
	std::queue<int> q = q1; 
    q1 = q2; 
    q2 = q; 
    return t; 
}

int size()
{
	return curr_size;
}

int main(int argc, char const *argv[])
{
	push(3);
	push(5);
	push(2);
	push(7);
	std::cout<<pop()<<" ";
	push(9);
	push(8);
	push(4);
	std::cout<<pop()<<std::endl;
	std::cout<<"Top element "<<top()<< '\n';
	std::cout<<"Size of stack " <<size();
	std::cout<<'\n';
	return 0;
}
