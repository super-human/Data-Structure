#include<iostream>
#include<climits>
#include<stack>

//Reverse the elements in the stack using only push and pop operation in O(n) extra space

void Push(std::stack<int>& s,int t)
{
	if(s.empty())
		s.push(t);
	else
	{
		int temp = s.top();
		s.pop();
		Push(s,t);
		s.push(temp);
	}
}

void reverse(std::stack<int>& s)
{
	if(s.empty())
		return;
	int t=s.top();
	s.pop();
	reverse(s);
	Push(s,t);
}

void display(std::stack<int> s)
{
	while(!s.empty())
	{
		std::cout<<s.top()<<" ";
		s.pop();
	}
	std::cout<<std::endl;
}


int main(int argc, char const *argv[])
{
	std::stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	std::cout<<"Before Reversing the stack: "<<std::endl;
	display(s);
	std::cout<<"After Reversing the stack: "<<std::endl;
	reverse(s);
	while(!s.empty())
	{
		std::cout<<s.top()<<" ";
		s.pop();
	}
	std::cout<<std::endl;
	return 0;
}
