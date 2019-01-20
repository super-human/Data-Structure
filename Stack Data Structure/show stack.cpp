#include <bits/stdc++.h>
#include<stack>
using namespace std;

void showstack(stack <int> s)
{
	while(!s.empty())
	{
		cout<<s.top()<<endl;
		s.pop();
	}
}

int main()
{
	/* code */
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	showstack(s);
	cout<<"size of the stack: ";
	cout<<s.size()<<endl;
	cout<<"top :";
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.size()<<endl; 
	showstack(s);
	return 0;
}
