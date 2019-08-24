#include <iostream>

//Implementing 2 stacks in one array. All push and pop operations take O(1) time and O(1)space complexity.

class Stacks
{
	int top1,top2;
	int *arr;
	int capacity;
public:
	Stacks(int capacity)
	{
		this->capacity=capacity;
		arr = new int[this->capacity];
		top1 = -1;
		top2 = this->capacity;
	}
	void push1(int x)
	{
		if(top1<top2-1)
			arr[++top1] = x;
		else
			std::cout<<"Stack Overflow"<<std::endl;
	}
	int pop1()
	{
		int x = -1;
		if(top1 == -1)
			std::cout<<"Stack Underflow"<<std::endl;	
		else
			int x=arr[top1--];
		return x;
	}

	void push2(int x)
	{
		if(top1<top2-1)
			arr[--top2]=x;
		else
			std::cout<<"Stack Overflow"<<'\n';
	}
	int pop2()
	{
		int x=-1;
		if(top2>capacity)
			std::cout<<"Stack Underflow"<<'\n';
		else
			x = arr[top2++];
		return x;
	}
	void display1()
	{
		for (int i = 0; i <= top1; ++i)
			std::cout<<arr[i]<<" ";
		std::cout<<'\n';
	}
	void display2()
	{
		for (int i = top2; i < capacity; ++i)
			std::cout<<arr[i]<<" ";
		std::cout<<'\n';
	}
};

int main(int argc, char const *argv[])
{
	Stacks s(5);
	s.push1(9);
	s.push2(8);
	s.push1(5);
	s.push1(4);
	s.push2(7);
	
	s.display1();
	s.display2();
	return 0;
}
