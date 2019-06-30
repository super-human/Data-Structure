#include<bits/stdc++.h>
using namespace std;

int isOperand(char s)
{
	if(s >= '0' && s <= '9')
		return 1;
	return 0;
}

int convert(string exp)
{
	stack<int> s;
	int x=0,y=0,operand = 0;
	for(int i=0;i<exp.length();i++)
	{
		if(exp[i] == ' ' || exp[i] == ',')
			continue;
		else if(isOperand(exp[i]))
		{
			operand = 0;
			while(i<exp.length() && isOperand(exp[i]))
			{
				operand = operand*10 + (exp[i]-'0');
				i++;
			}
			i--;
			s.push(operand);
		}
		else
		{
			x = s.top();
			s.pop();
			y = s.top();
			s.pop();
			if(exp[i] == '+')
				s.push(y+x);
			else if(exp[i] == '-')
				s.push(y-x);
			else if(exp[i] == '*')
				s.push(y*x);
			else if(exp[i] == '/')
				s.push(y/x);
		}
	}
	return s.top();
}

int main(int argc, char const *argv[])
{
	string str;
	getline(cin,str);
	cout<<convert(str)<<endl;
	return 0;
}
