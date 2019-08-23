#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node *next;
};
class linkedlist:public node
{
	node *top = NULL;
public:
	void push(int);
	void pop();
	void show();
	void reverse();
};
void linkedlist::push(int x)
{
	node *temp=new node;
	temp->data=x;
	temp->next=top;
	top=temp;
}
void linkedlist::pop()
{
	node *temp;
	if(top == NULL)
		return;
	temp=top;
	top=top->next;
	free(temp);
}
void linkedlist::show()
{
	node *temp=top;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

void linkedlist::reverse()
{
	node *prev=NULL,*current=top,*next=top;
	while(current)
	{
		next = current->next;
		current->next = prev;
		prev=current;
		current= next;
	}
	top = prev;

}
int main(int argc, char const *argv[])
{
	
	linkedlist l;
	l.push(10);
	l.push(20);
	l.push(30);
	l.push(40);
	l.pop();
	l.show();
	std::cout<<'\n';
	l.reverse();
	l.show();
	std::cout<<'\n';

	return 0;
}
