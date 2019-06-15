#include<bits/stdc++.h>
using namespace std;
void swap(char *a, char *b)
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void perm(char s[],int l, int h)
{

	if(l==h)
		cout<<s<<endl;
	else
	{
		for (int i = l; i < h; ++i)
		{
			/* code */
			swap(s[l],s[i]);
			perm(s,l+1,h);
			swap(s[l],s[i]);
		}
	}
}
int main(int argc, char const *argv[])
{
	char s[]="ABC";
	perm(s,0,3);
	return 0;
}