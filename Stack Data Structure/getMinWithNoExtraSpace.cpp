#include<iostream>
#include<string.h>
#include<climits>

//Design a stack such that access to the minimum element in the stack is O(1)


class Stack
{
	int top;
	int *st;
	int capacity;
	int minElement;
public:
	Stack()
	{
		top=-1;
		capacity=1;
		st=new int[capacity];
		minElement=INT_MAX;
	}
	void push(int x)
	{
		if(isFull())
			doublestack();
		
		if(isEmpty())
		{
			minElement=x;
			st[++top]=x;
		}
		else
		{
			if(x<minElement)
			{
				st[++top] = 2*x-minElement;
				minElement = x;
			}
			else
				st[++top] = x;
		}

	}
	void pop()
	{
		if(isEmpty())
		{
			std::cout<<"Underflow"<<std::endl;
			return;
		}
		if(st[top]<minElement)
			minElement = 2*minElement-st[top];
		top--;
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
	int getmin()
	{
		return minElement;
	}
};



int main(int argc, char const *argv[])
{
	Stack S;
	S.push(3); 
    S.push(5); 
    std::cout<<S.getmin()<<'\n'; 
    S.push(2); 
    S.push(1); 
    std::cout<<S.getmin()<<'\n'; 
    S.pop(); 
    std::cout<<S.getmin()<<'\n'; 
    S.pop(); 
    std::cout<<S.peek()<<'\n'; 
	return 0;
}
