#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>

// k stacks in a single array with space optimization i.e. no wastage of space

class Stack
{
	int *arr;
	int *top;
	int *next;
	int n,k;
	int free;

public:
	Stack(int k,int n)
	{
		this->k=k;
		this->n = n;
		arr = new int[this->n];
		top = new int[this->k];
		next = new int[this->n];
		free = 0;
		for (int i = 0; i < k; ++i)
			top[i] = -1;
		for (int i = 0; i < n-1; ++i)
			next[i] = i+1;
		next[n-1] = -1;
	}

	void push(int data, int sn)
	{
		if(isFull())
		{
			std::cout<<"Stack Overflow"<<'\n';
			return;
		}
		int index = free;
		free = next[index];
		next[index] = top[sn];
		top[sn] = index;
		arr[index] = data;
	}

	int pop(int sn)
	{
		if(isEmpty(sn))
		{
			std::cout<<"Stack Underflow"<<'\n';
			return INT_MAX;
		}
		int index = top[sn];
		top[sn] = next[index];
		next[index] = free;
		free = index;
		return arr[index];
	}
	bool isEmpty(int sn)
	{
		return (top[sn]==-1);
	}
	bool isFull()
	{
		return (free == -1);
	}
};

int main(int argc, char const *argv[])
{
	Stack s(3,10);
	// Let us put some items in stack number 2 
    s.push(15, 2); 
    s.push(45, 2); 
  
    // Let us put some items in stack number 1 
    s.push(17, 1); 
    s.push(49, 1); 
    s.push(39, 1); 
  
    // Let us put some items in stack number 0 
    s.push(11, 0); 
    s.push(9, 0); 
    s.push(7, 0); 
  
    std::cout << "Popped element from stack 2 is " << s.pop(2) << std::endl; 
    std::cout << "Popped element from stack 1 is " << s.pop(1) << std::endl; 
    std::cout << "Popped element from stack 0 is " << s.pop(0) << std::endl; 

	return 0;
}
