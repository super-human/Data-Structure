#include<bits/stdc++.h>

//Evaluating infix expression without converting it into postfix in a single scan

int isoperand(char x)
{
	if(x == '+' || x=='-'|| x=='*' || x=='/' || x==')' || x=='(')
		return 0;
	return 1;
}

int Pre(char x)
{
	if(x == '+' || x == '-')
		return 1;
	if(x == '*' || x == '/')
		return 3;
	return 0;
}

int postfixevaluation(std::string exp)
{
	std::stack<int> s1;
	std::stack<char> s2;
	int i,x,y,z,key;
	i=0;
	while(exp[i]!='\0')
	{
		
		if(isoperand(exp[i]))
		{
			key = exp[i]-'0';
			s1.push(key);
			i++;
		}
		else if(!isoperand(exp[i]) && s2.empty())
			s2.push(exp[i++]);
		else if(!isoperand(exp[i]) && !s2.empty())
		{
			if(exp[i]=='(')
				s2.push(exp[i++]);
			else if(Pre(exp[i])>Pre(s2.top()) && exp[i]!=')')
				s2.push(exp[i++]);
			else if(exp[i]==')' && s2.top() == '(')
			{
				s2.pop();
				i++;
			}
			
			else
			{
				x = s1.top();
				s1.pop();
				y = s2.top();
				s2.pop();
				z = s1.top();
				s1.pop();
				if(y == '+')
					s1.push(z+x);
				else if(y == '-')
					s1.push(z-x);
				else if(y == '*')
					s1.push(x*z);
				else if(y == '/')
					s1.push(z/x);
			} 
		}
	}
	while(!s2.empty())
	{
		x = s1.top();
		s1.pop();
		y = s2.top();
		s2.pop();
		z = s1.top();
		s1.pop();
		if(y == '+')
			s1.push(x+z);
		else if(y == '-')
			s1.push(z-x);
		else if(y == '*')
			s1.push(x*z);
		else if(y == '/')
			s1.push(z/x);
	}
	return s1.top();
}

int main(int argc, char const *argv[])
{
	std::string s;
	getline(std::cin,s);
	std::cout<<postfixevaluation(s)<<std::endl;
	return 0;
}
