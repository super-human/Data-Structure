#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s = "finding";
	int h[26] = {0};
	for (int i = 0; i<s.length(); ++i)
	{
		/* code */
		h[s[i]-97] +=1;
	}
	for (int i = 0; i < 26; ++i)
	{
		/* code */
		if(h[i]>1)
		{
			cout<<char(i+97)<<endl;
			cout<<h[i]<<endl;
		}	
	}
	return 0;
}