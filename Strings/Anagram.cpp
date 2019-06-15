#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s1 = "decimal";
	string s2 = "medical";
	int h[26] = {0};
	int i;
	for (i = 0; s1[i]!='\0'; ++i)
	{
		/* code */
		h[s1[i]-97] +=1;
	}
	for (i = 0; s2[i]!='\0'; ++i)
	{
		/* code */
		h[s2[i]-97] -=1;
		if (h[s2[i]-97]<0)
		{
			/* code */
			cout<<"Not anagram"<<endl;
			break;
		}
		
	}
	if(s2[i] == '\0')
			cout<<"anagram"<<endl;

	return 0;
}
