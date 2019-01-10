#include<iostream>
#include<stdlib.h>

using namespace std;

class node
{
public:
	int data;
	node *next;
	node *prev;
};
class list:public node
{
	node *head, *tail;
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
	temp->prev=NULL;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		tail=temp;
	}
	else
	{
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
}
void list::insertatlast(int data)
{
	node *temp=new node;
	temp->data=data;
	if(head==NULL)
	{
		head=temp;
		tail=head;
	}
	else
	{
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
		tail->next=NULL;
	}
}
void list::insertatlocation(int data, int pos)
{
	node *temp=new node;
	temp->data=data;
	if(head==NULL && pos>1)
	{
		cout<<"Position doesn't exist"<<endl;
		return;
	}
	else
	{
		node *ptr;
		ptr=head;
		int count=1;
		while(count<pos && ptr!=NULL)
		{
			ptr=ptr->next;
			count++;
		}
		if(count==pos)
		{
			temp->prev=ptr->prev;
			temp->next=ptr;
			ptr->prev->next=temp;
			ptr->prev=temp;
		}
		else
		{
			cout<<"Position doesnot exist"<<endl;;
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
	if(head==NULL)
	{
		cout<<"No list to be deleted"<<endl;
		return 0;
	}
	else
	{
		node *ptr=head;
		int del_data;
		head=head->next;
		del_data=ptr->data;
		free(ptr);
		return del_data;
	}
}

int list::delete_lastnode()
{
	if(head==NULL)
	{
		cout<<"No list to be deleted"<<endl;
		return 0;
	}
	else
	{
		node *ptr;
		int del_data;
		ptr=tail;
		del_data=tail->data;
		tail=tail->prev;
		tail->next=NULL;
		free(ptr);
		return del_data;
	}
}

int list::delete_intermediatenode(int pos)
{
	if(head==NULL && pos>1)
	{
		cout<<"No list found"<<endl;
		return 0;
	}
	else
	{
		node *ptr=head;
		int count=1;
		while(count<pos && ptr!=NULL)
		{
			ptr=ptr->next;
			count++;
		}
		if(count==pos)
		{
			ptr->prev->next=ptr->next;
			ptr->next->prev=ptr->prev;
			int del_data=ptr->data;
			free(ptr);
			return del_data;
		}
		else
		{
			cout<<"Wrong Position"<<endl;
			return 0;
		}
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
}