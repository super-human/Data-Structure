#include <iostream>
#include <stdlib.h>
using namespace std;

class node
{
public:
	int data;
	node* next;
};
class list:public node
{
	node *head,*tail;
public:
	list()
	{
		head=NULL;
		tail=NULL;
	}
	void insertatbegin(int);
	void insertatlast(int);
	void insertatlocation(int,int);
	int delete_firstnode();
	int delete_lastnode();
	int delete_intermediatenode(int);
	void display();
};
void list::insertatbegin(int data)
{
	node *temp=new node;
	temp->data=data;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		tail=head;
	}
	else
	{
		temp->next=head;
		head=temp;
	}

}
void list::insertatlast(int data)
{
	node *temp=new node;
	temp->data=data;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		tail=head;
	}
	else
	{
		tail->next=temp;
		tail=temp;
	}
}
void list::insertatlocation(int data,int p)
{
	node *temp=new node;
	node *ptr,*prev;
	int count=1;
	temp->data=data;
	temp->next=NULL;
	if(head==NULL && p>1)
	{
		cout<<"Position does not exist"<<endl;
		return;
	}
	
	else
	{
		ptr=head;
		prev=head;
		while(count!=p && ptr!=NULL)
		{
			prev=ptr;
			ptr=ptr->next;
			count++;
		}
		
		if(p<=count+1)
		{
			temp->next=ptr;
			prev->next=temp;
		}
		else
		{
			cout<<"Wrong position"<<endl;
			return;
		}
	}
}
void list::display()
{
	node *ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<endl;
		ptr=ptr->next;
	}
}
int list::delete_firstnode()
{
	node *ptr;
	int del_data;
	ptr=head;
	if(head==NULL)
	{
		cout<<"No list found"<<endl;
		return 0;
	}
	else
	{
		del_data=head->data;
		head=head->next;
		free(ptr);
		return del_data;
	}
}
int list::delete_lastnode()
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
		prev=head;
		while(ptr!=tail)
		{
			prev=ptr;
			ptr=ptr->next;
		}
		tail=prev;
		prev->next=NULL;
		del_data=ptr->data;
		free(ptr);
		return del_data;
	}
}
int list::delete_intermediatenode(int pos)
{
	
	if(head==NULL)
	{
		cout<<"No list found"<<endl;
		return 0;
	}
	else
	{
		node *ptr,*prev;
		ptr=head;
		prev=head;
		int count=1;
		while(count<pos)
		{
			prev=ptr;
			ptr=ptr->next;
			count++;
		}
		prev->next=ptr->next;
		int del_data=ptr->data;
		free(ptr);
		return del_data;
	}
}

int main()
{
	int ch,data,pos;
	list l;
	while(1)
	{
		cout<<"\n**** MENU ****"<<endl;
        cout<<"1:INSERT_AT_BEGIN\n2:INDERT_AT_LAST\n3:INSERT_AT_LOCATION\n4:DELETE_FIRST_NODE\n5:DELETE_LASTNODE\n6:DELETE_INTERMEDIATENODE\n7:DISPLAY\n8:EXIT\n";
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
        	case 3: cin>>data;
        			cin>>pos;
        			l.insertatlocation(data,pos);
        			break;
        	case 4: cout<<l.delete_firstnode();
        			break;
        	case 5: cout<<l.delete_lastnode();
        			break;
        	case 6: cin>>pos;
        			cout<<l.delete_intermediatenode(pos);
        			break;
        	case 7: l.display();
        			break;
        	case 8: return 0;

        }
	}
	return 0;
}