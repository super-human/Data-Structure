#include<bits/stdc++.h>
using namespace std;

int isOperand(char s)
{
	if(s == '+' || s == '-' || s == '*' || s == '/')
		return 0;
	return 1;
}

int convert(string exp)
{
	stack<int> s;
	int x=0,y=0;
	for(int i=0;i<exp.length();i++)
	{
		if(isOperand(exp[i]))
			s.push(exp[i]-'0');
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
	cin>>str;
	cout<<convert(str)<<endl;
	return 0;
}