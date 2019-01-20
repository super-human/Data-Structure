#include<bits/stdc++.h>
using namespace std;

#define MAX 101

class Stack
{
	int A[MAX];
	int top;
public:
	Stack()
	{ 
		top = -1; 
	}
	void push(int);
	void pop();
	void print();
};
void Stack::push(int x)
{

	if(top == MAX-1)
	{
		cout<<"Error: stack overflown"<<endl;
		return;
	}
	A[++top]=x;
}
void Stack::pop()
{
	if(top == -1)
	{
		cout<<"Error: stack underflow"<<endl;
		return;
	}
	top--;
}
void Stack::print()
{
	int i;
	if(top == -1)
		return;
	for(i=0;i<=top;i++)
	{
		cout<<A[i]<<endl;
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.pop();
	s.print();
	return 0;
}