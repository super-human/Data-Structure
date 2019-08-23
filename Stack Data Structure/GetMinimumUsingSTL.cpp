#include<iostream>
#include <stack>

//Design a stack such that access to the minimum element in the stack is O(1)

int main(int argc, char const *argv[])
{
	int no_of_elements,element;
	std::stack<int> elementStack,minStack;
	std::cin>>no_of_elements;
	while(no_of_elements--)
	{
		std::cin>>element;
		elementStack.push(element);
		if(minStack.empty())
			minStack.push(element);
		else
			if(elementStack.top()<minStack.top())
				minStack.push(element);
	}
	std::cout<<"Enter no. of elements you want to pop"<<std::endl;
	std::cin>>no_of_elements;
	while(no_of_elements--)
	{
	    if(elementStack.top() == minStack.top())
	        minStack.pop();
	   elementStack.pop();
	}
	std::cout<<"Minimum element in the stack is :"<<minStack.top()<<std::endl;
	return 0;
}
