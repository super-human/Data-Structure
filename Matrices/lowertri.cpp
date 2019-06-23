

//Lower Triangular Matrix using row major formula

#include<bits/stdc++.h>
using namespace std;

class LowerTri
{
	int n;
	int *A;
public:
	LowerTri(int n)
	{
		this->n=n;
		A = new int[n*(n+1)/2];	
	}
	~LowerTri()
	{
		delete []A;
	}
	void set(int i, int j, int x);
	int get(int i, int j);
	void display();
	
};

void LowerTri::set(int i, int j, int x)
{
	if(i>=j)
		A[i*(i-1)/2+j-1]=x;
}
int LowerTri::get(int i, int j)
{
	if(i>=j)
		cout<<A[i*(i-1)/2+j-1]<<endl;
	else
		return 0;
}
void LowerTri::display()
{
	for (int i = 1; i <= n; ++i)
	{
		/* code */
		for (int j = 1; j <= n; ++j)
		{
			/* code */
			if(i>=j)
				cout<<A[i*(i-1)/2+j-1]<<" ";
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
	LowerTri lm(d);
	int x;
	cout<<"Enter All Elements";
	for(int i=1;i<=d;i++)
	{
		for(int j=1;j<=d;j++)
		{
			cin>>x;
			lm.set(i,j,x);
		}
	}
lm.display();
	return 0;
}