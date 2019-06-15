#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s = "finding";
	long int h = 0, x=0;
	for (int i = 0; i < s.length(); ++i)
	{
		/* code */
		x=1;
		x = x<<s[i]-97;
		if(x&h)
			cout<<s[i]<<endl;
		else
			h=x|h;
	}
	return 0;
}