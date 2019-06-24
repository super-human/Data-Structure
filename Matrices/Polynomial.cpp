#include<bits/stdc++.h>
using namespace std;

class Term
{
public:
	int coeff;
	int exp;
};

class Poly
{
	int n;
	Term *t;
public:
	Poly(int n)
	{
		this->n = n;
		t = new Term[this->n];
	}
	friend istream & operator>>(istream &is, Poly &s);
	friend ostream & operator<<(ostream &os, Poly &s);
	Poly operator+(Poly &s);
};

istream & operator>>(istream &is, Poly &s)
{
	cout<<"Enter coefficient and exponents"<<endl;
	for (int i = 0; i < s.n; ++i)
	{
		/* code */
		cin>>s.t[i].coeff>>s.t[i].exp;
	}
	return is;
}

ostream & operator<<(ostream &os, Poly &s)
{
	for (int i = 0; i < s.n; ++i)
	{
		/* code */
		cout<<s.t[i].coeff<<"x"<<s.t[i].exp;
		if(i == s.n-1)
			cout<<" ";
		else
			cout<<"+";
	}
	cout<<endl;
	return os;
}

Poly Poly::operator+(Poly &s)
{
	int i,j,k = 0;
	Poly *sum = new Poly(n + s.n);
	
	while(i<n && j<s.n)		
	{
		if(t[i].exp > s.t[j].exp)
			sum->t[k++] = t[i++];
		else if(t[i].exp < s.t[j].exp)
			sum->t[k++] = s.t[j++];
		else
		{
			sum->t[k].exp = t[i].exp;
			sum->t[k++].coeff = t[i++].coeff + s.t[j++].coeff;
		}
	
	}	
	for(;i<n;i++)
		sum->t[k++]=t[i];
	for(;j<s.n;j++)
		sum->t[k++]=s.t[j];
	sum->n = k;
	return *sum;
}

int main(int argc, char const *argv[])
{
	Poly p1(3);
	Poly p2(5);
	cin>>p1;
	cin>>p2;
	Poly sum = p1+p2;
	cout<<p1;
	cout<<p2;
	cout<<sum;

	return 0;
}