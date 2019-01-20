#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
	int data;
	node *npx;
};
class list
{
public:
	void insert(node **,int);
	node* XOR(node*, node*);
	void printlist(node*);
};
void list::insert(node **head, int data)
{
	node *temp=new node;
	temp->data=data;
	temp->npx=*head;
	if(*head==NULL)
	{
		*head=temp;
		return;
	}
	(*head)->npx=XOR(temp,(*head)->npx);
	*head=temp;
}
void list::printlist(node *head)
{
	node *prev=NULL,*current;
	while(head!=NULL)
	{
		cout<<head->data<<endl;
		current=head;
		head=XOR(prev,head->npx);
		prev=current;
	}
}
node* list:: XOR(node *a,node *b)
{
    return (struct node*) ((unsigned long) (a) ^ (unsigned long) (b));
}
int main()
{
	node *head=NULL;
	list l;
	l.insert(&head,10);
	l.insert(&head,20);
	l.insert(&head,30);
	l.insert(&head,40);
	l.printlist(head);
	return 0;
}
