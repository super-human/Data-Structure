

//Upper Matrix using row major formula

#include<bits/stdc++.h>
using namespace std;

class UpperTri
{
	int n;
	int *A;
public:
	UpperTri(int n)
	{
		this->n=n;
		A = new int[n*(n+1)/2];	
	}
	~UpperTri()
	{
		delete []A;
	}
	void set(int i, int j, int x);
	int get(int i, int j);
	void display();
	
};

void UpperTri::set(int i, int j, int x)
{
	if(i>=j)
		A[((i-1)*n - (i-2)(i-1)/2) +j-i]=x;
}
int UpperTri::get(int i, int j)
{
	if(i>=j)
		cout<<A[((i-1)*n - (i-2)(i-1)/2) +j-i]<<endl;
	else
		return 0;
}
void UpperTri::display()
{
	for (int i = 1; i <= n; ++i)
	{
		/* code */
		for (int j = 1; j <= n; ++j)
		{
			/* code */
			if(i>=j)
				cout<<A[((i-1)*n - (i-2)(i-1)/2) +j-i]<<" ";
			else
				cout<<"0 ";
		}
		cout<<endl;
	}
}

int main()
{
	int d;
	cout<<"Enter Dimensions";
	cin>>d;
	UpperTri um(d);
	int x;
	cout<<"Enter All Elements";
	for(int i=1;i<=d;i++)
	{
		for(int j=1;j<=d;j++)
		{
			cin>>x;
			um.set(i,j,x);
		}
	}
um.display();
	return 0;
}