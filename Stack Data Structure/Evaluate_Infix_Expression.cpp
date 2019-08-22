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
	std::stack<int> operandStack;
	std::stack<char> operatorStack;
	int i,x,y,z,operand;
	i=0;
	while(exp[i]!='\0')
	{
		if(exp[i]==' ' || exp[i]==',')
		{
			i++;
			continue;
		}
		
		if(isoperand(exp[i]))
		{
			operand = 0;
			while(i<exp.length() && isoperand(exp[i]))
				operand = operand*10 + (exp[i++]-'0');
			operandStack.push(operand);
			
		}
		else if(!isoperand(exp[i]) && operatorStack.empty())
			operatorStack.push(exp[i++]);
		else if(!isoperand(exp[i]) && !operatorStack.empty())
		{
			if(exp[i]=='(')
				operatorStack.push(exp[i++]);
			else if(Pre(exp[i])>Pre(operatorStack.top()) && exp[i]!=')')
				operatorStack.push(exp[i++]);
			else if(exp[i]==')' && operatorStack.top() == '(')
			{
				operatorStack.pop();
				i++;
			}
			
			else
			{
				x = operandStack.top();
				operandStack.pop();
				y = operatorStack.top();
				operatorStack.pop();
				z = operandStack.top();
				operandStack.pop();
				if(y == '+')
					operandStack.push(z+x);
				else if(y == '-')
					operandStack.push(z-x);
				else if(y == '*')
					operandStack.push(x*z);
				else if(y == '/')
					operandStack.push(z/x);
			} 
		}
	}
	while(!operatorStack.empty())
	{
		x = operandStack.top();
		operandStack.pop();
		y = operatorStack.top();
		operatorStack.pop();
		z = operandStack.top();
		operandStack.pop();
		if(y == '+')
			operandStack.push(x+z);
		else if(y == '-')
			operandStack.push(z-x);
		else if(y == '*')
			operandStack.push(x*z);
		else if(y == '/')
			operandStack.push(z/x);
	}
	return operandStack.top();
}

int main(int argc, char const *argv[])
{
	std::string s;
	getline(std::cin,s);
	std::cout<<postfixevaluation(s)<<std::endl;
	return 0;
}
