#include<bits/stdc++.h>
using namespace std;

int isOperand(char s)
{
	if(s == '+' || s == '-' || s == '*' || s == '/')
		return 0;
	return 1;
}

int Pre(char s)
{
	if(s == '+' || s == '-')
		return 1;
	else if(s == '*' || s == '/')
		return 2;
	return 0;
}

char* convert(string exp)
{
	char *post = new char[exp.length()];
	stack<char> S;
	S.push('#');
	int i,j;
	i=j=0;
	while(exp[i]!='\0')
	{
		if(isOperand(exp[i]))
			post[j++] = exp[i++];
		else
		{
			if(Pre(exp[i])>Pre(S.top()))
				S.push(exp[i++]);
			else
			{
				post[j++] = S.top();
				S.pop();
			}
		}
	}

	while(!S.empty())
	{
		post[j++] = S.top();
		S.pop();
	}
	post[j-1] = '\0';
	return post;
}

int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	cout<<convert(str)<<endl;
	return 0;
}
