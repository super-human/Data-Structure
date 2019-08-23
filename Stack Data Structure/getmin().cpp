#include<iostream>
#include<string.h>

//Design a stack such that access to the minimum element in the stack is O(1)


class Stack
{
	int top;
	int *st;
	int capacity;
public:
	Stack()
	{
		top=-1;
		capacity=1;
		st=new int[capacity];
	}
	void push(int x)
	{
		if(isFull())
			doublestack();

		st[++top]=x;

	}
	int pop()
	{
		if(isEmpty())
			std::cout<<"Underflow"<<std::endl;
		else
			return st[top--];
	}
	void display()
	{
		for (int i = top; i<=0; ++i)
			std::cout<<st[top]<<std::endl;
	}
	int peek()
	{
			return st[top];
	}
	void doublestack()
	{
		int *temp = new int[capacity*2];
		memcpy(temp,st,sizeof(int)*2);
		delete[] st;
		st=temp;
		capacity = capacity*2;
	}
	bool isEmpty() 
	{ 
    	if(top == -1) 
        	return true; 
    	return false; 
	} 
	bool isFull() 
	{ 
    	if(top == capacity - 1) 
        	return true; 
    	return false; 
	} 
};

class AdvanceStack: public Stack
{
	Stack minStack;
public:
	void push(int);
	int pop();
	int getmin();
};

void AdvanceStack::push(int x)
{
	if(isEmpty())
	{
		Stack::push(x);
		minStack.push(x);
	}
	else
	{
		Stack::push(x);
		if(x<=minStack.peek())
			minStack.push(x);
	}
}

int AdvanceStack::pop()
{
	int x=Stack::pop();
	int y = minStack.pop();
	if(y!=x)
		minStack.push(y);
	return x;
}

int AdvanceStack::getmin()
{
	return minStack.peek();
}
int main(int argc, char const *argv[])
{
	AdvanceStack S;
	S.push(10);
	S.push(5);
	S.push(6);
	S.push(9);
	S.push(12);
	std::cout<<S.getmin()<<std::endl;
	S.push(1);
	std::cout<<S.getmin()<<std::endl;
	return 0;
}
