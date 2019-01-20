#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 101

class Stack
{
	int top;
	int capacity;
	int *arr;
public:
	Stack()
	{
		top=-1;
		capacity=MAX_SIZE;
		arr=new int[MAX_SIZE];
	}
	void push(int);
	void pop();
	bool isempty();
	bool isfull();
	void print();
};
void Stack::push(int data)
{
	if(isfull())
	{
		cout<<"Error: Stack overflow"<<endl;
		return;
	}
	arr[++top]=data;
}
void Stack::pop()
{
	if(isempty())
	{
		cout<<"Error: Stack underflow"<<endl;
		return;
	}
	top--;
}
bool Stack::isempty()
{
	if(top == -1)
		return true;
	return false;
}
bool Stack::isfull()
{
	if(top == MAX_SIZE-1)
		return true;
	return false;
}
void Stack::print()
{
	int i;
	for(i=0;i<=top;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.pop();
	s.print();
	return 0;
}