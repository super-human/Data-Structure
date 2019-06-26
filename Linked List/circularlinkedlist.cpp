#include <iostream>
#include<stdlib.h>

using namespace std;

class node
{
public:
	int data;
	node *next;
};
class circularll:public node
{
	node *head,*tail;
public:
	circularll()
	{
		head=NULL;
		tail=NULL;
	}
	void insertatbegin(int);
	void insertatlast(int);
	void insertatanypos(int, int);
	int deletefirstnode();
	int deletelastnode();
	int deleteatanypos(int);
	int length();
	void display();
};

void circularll::insertatbegin(int data)
{
	node *temp=new node;
	
	temp->data=data;
	if(head==NULL)
	{
		head=temp;
		tail=temp;
		temp->next=head;
	}
	else
	{
		temp->next=head;
		tail->next=temp;
		head=temp;
	}
}

void circularll::insertatlast(int data)
{
	node *temp=new node;
	temp->data=data;
	temp->next=temp;
	if(tail==NULL)
	{
		head=temp;
		tail=temp;
	}
	else
	{
		temp->next=tail->next;
		tail->next=temp;
		tail=temp;
	}
}

void circularll::insertatanypos(int x, int pos)

{
	node *temp,*ptr;
	ptr= head;
	if(head == NULL && pos == 0)
	{
		temp = new node;
		temp->data = x;
		head= temp;
		temp->next = head;
		tail = temp;
	}
	else if(head == NULL && pos>0)
		return ;
	else
	{
		for(int i=1;i<=pos-1 && ptr;i++)
			ptr = ptr->next;
		if(ptr->next == head)
			insertatlast(x);
		else if(ptr)
		{
			temp->next = ptr->next;
			ptr->next = temp;
		}
	}
}
int circularll::deletefirstnode()
{
	if(head==NULL)
	{
		cout<<"No list found"<<endl;
		return 0;
	}
	else
	{
		node *ptr=head;
		int del_data;
		del_data=ptr->data;
		head=ptr->next;
		tail->next=head;
		free(ptr);
		return del_data;
	}
}
int circularll::deletelastnode()
{
	if(head==NULL)
	{
		cout<<"No list found"<<endl;
		return 0;
	}
	else
	{
		node *ptr,*prev;
		int del_data;
		ptr=head;
		while(ptr->next!=head)
		{
			prev=ptr;
			ptr=ptr->next;
		}
		tail=prev;
		tail->next=head;
		del_data=ptr->data;
		free(ptr);
		return del_data;
	}
}

int circularll::deleteatanypos(int pos)
{
	int del_data;
	node *q;
	if(head == NULL)
	{
		cout<<"No list found"<<endl;
		return 0;
	}
	if(pos<0 || pos>length())
		return -1;
	if(pos == 0)
		deletefirstnode();
	else
	{
		node *ptr = head;
		for (int i = 1; i <= pos - 2; ++i)
			ptr = ptr->next;
		if(ptr->next->next == head)
			deletelastnode();
		else
		{
			del_data = ptr->next->data;
			q = ptr->next;
			del_data = q->data;
			free(q);
			ptr->next = ptr->next->next;
			return del_data;
		}
	}
}
int circularll::length()
{
	node *ptr = head;
	int count = 0;
	if(head == NULL)
		return 0;
	else
	{
		do
		{
			ptr = ptr->next;
			count++;
		}while(ptr!=head);
		return count;
	}
	
}
void circularll::display()
{
	node *current;
	current=head;
	if(head==NULL)
	{
		cout<<"No list found"<<endl;
		return;
	}
	
	do
	{
		cout<<current->data<<endl;
		current=current->next;
	} while(current!=head);
}

int main()
{
	int ch,data,pos;
	circularll l;
	while(1)
	{
		cout<<"\n**** MENU ****"<<endl;
        cout<<"1:INSERT_AT_BEGIN\n2:INDERT_AT_LAST\n3:DELETE_FIRST_NODE\n4:DELETE_LASTNODE\n5:DISPLAY\n6:INSERT_AT_ANY_POS\n7:DELETE_AT_ANY_POS\n8:EXIT\n";
        cout<<"\nEnter Your Choice:";
        cin>>ch;
        switch(ch)
        {
        	case 1: cin>>data;
        			l.insertatbegin(data);
        			break;
        	case 2: cin>>data;
        			l.insertatlast(data);
        			break;
        	case 3: cout<<l.deletefirstnode();
        			break;
        	case 4: cout<<l.deletelastnode();
        			break;
        	case 5: l.display();
        			break;
        	case 6: cin>>data>>pos;
        			l.insertatanypos(data,pos);
        			break;

        	case 7: cin>>pos;
        			l.deleteatanypos(pos);
        			break;

        	case 8: return 0;

        }
	}
	return 0;
}
