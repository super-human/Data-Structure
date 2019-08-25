#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>

int main(int argc, char const *argv[])
{
	std::string exp;
	std::string no_duplicate;
	std::cin>>exp;
	int i = 1,j=0;
	std::stack<char> s;
	s.push(exp[0]);
	no_duplicate.resize(exp.length());
	no_duplicate[j] = s.top();
	while(exp[i]!='\0')
	{
		if(s.top() != exp[i])
		{
			s.push(exp[i]);
			no_duplicate[++j] = s.top();
		}
		else
		{
			s.pop();
			j--;
		}
		i++;
	}
	no_duplicate[j+1] = '\0';
	std::cout<<no_duplicate<<std::endl;
	return 0;
}
