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
	int deletefirstnode();
	int deletelastnode();
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
        cout<<"1:INSERT_AT_BEGIN\n2:INDERT_AT_LAST\n3:DELETE_FIRST_NODE\n4:DELETE_LASTNODE\n5:DISPLAY\n6:EXIT\n";
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
        	case 6: return 0;

        }
	}
	return 0;
}