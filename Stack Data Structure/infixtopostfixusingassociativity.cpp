#include<bits/stdc++.h>
using namespace std;

int isOperand(char s)
{
	if(s == '+' || s == '-' || s == '*' || s == '/' || s == '^' || s == '(' || s == ')')
		return 0;
	return 1;
}

int OutPre(char s)
{
	if(s == '+' || s == '-')
		return 1;
	else if(s == '*' || s == '/')
		return 3;
	else if(s == '^')
		return 6;
	else if(s == '(')
		return 7;
	return 0;
}

int InPre(char s)
{
	if(s == '+' || s == '-')
		return 2;
	else if(s == '*' || s == '/')
		return 4;
	else if(s == '^')
		return 5;
	return 0;
}

char* infixtopostfix(string exp)
{
	char *post = new char[exp.length()];
	stack<char> s;
	s.push('#');
	int i,j;
	i=j=0;
	while(exp[i]!='\0')
	{
		if(isOperand(exp[i]))
			post[j++] = exp[i++];
		else
		{
			if(exp[i] == '(')
				s.push(exp[i++]);
			else if(exp[i] == ')' && s.top() == '(')
			{
				s.pop();
				i++;
			}
			else if(OutPre(exp[i])>InPre(s.top()))
				s.push(exp[i++]);

			else
			{
				post[j++] = s.top();
				s.pop();
			}
		}
	}

	while(!s.empty())
	{
		post[j++] = s.top();
		s.pop();
	}
	post[j-1] = '\0';
	return post;
}

int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	cout<<infixtopostfix(str)<<endl;
	return 0;
}