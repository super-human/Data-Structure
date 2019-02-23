#include <bits/stdc++.h>
using namespace std;

class Stack
{
	int top;
	int capacity;
	int *arr;
public:
	Stack()
	{
		top=-1;
		capacity=1;
		arr= new int[capacity];
	}
	void push(int);
	void pop();
	bool isfull();
	bool isempty();
	void print();
	void doublestack(int);
};
void Stack::push(int x)
{
	if(isfull())
	{
		doublestack(x);
		return;
	}
	arr[++top]=x;
}
void Stack::pop()
{
	if(isempty())
	{
		cout<<"Error: Stack underflow";
		return;
	}
	top--;
}

bool Stack::isempty()
{
	if(top==-1)
		return true;
	return false;
}
bool Stack::isfull()
{
	if(top==capacity-1)
		return true;
	return false;
}
void Stack::print()
{
	while(top!=-1)
	{
	    cout<<arr[top]<<" ";
	    top--;
	}
	cout<<endl;
}
void Stack::doublestack(int x)
{
	int* temp=new int[capacity*2];
	memcpy(temp,arr,sizeof(int)*capacity);
	delete[] arr;
	arr=temp;
	arr[++top]=x;
	capacity *=2;
}
int main(int argc, char const *argv[])
{
	Stack s;
	s.push(2);
	s.push(4);
	s.push(6);
	s.push(8);
	s.pop();
	s.print();
	return 0;
}