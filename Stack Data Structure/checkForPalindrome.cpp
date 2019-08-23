#include<iostream>
#include<string.h>
#include<climits>
#include<stack>

// Given an array of characters  formed with a's and b's with special character X which represents middle of the list.
// Check for the palindrome.

int main(int argc, char const *argv[])
{
	std::string exp;
	std::cin>>exp;
	std::stack<char> s;
	int i=0,flag = 0;
	while(exp[i]!='X' && i<exp.length())
		s.push(exp[i++]);
	i++;
	while(i<exp.length())
	{
		if(s.top()!=exp[i] || !s.empty())
		{
			flag = 1;
			break;
		}
		s.pop();
		i++;
	}
	if(flag == 1)
		std::cout<<"Not a Palindrome"<<std::endl;
	else
		std::cout<<"Palindrome"<<std::endl;
	return 0;
}
