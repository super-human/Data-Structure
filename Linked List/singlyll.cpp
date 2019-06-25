#include <iostream>
#include <stdlib.h>
#include<stack>
using namespace std;

class node
{
public:
	int data;
	node* next;
};
class linkedlist:public node
{
	node *head,*tail;
public:
	linkedlist()
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
	void delete_linkedlist();
	void search_element(int);
	void get_node(int);
	void get_node_from_end(int);
	void middle_element();
	void count_given_key(int);
	bool detect_loop();
	bool IsPalindrome();
	void delete_duplicates_from_sortedll();
	void swap_nodes_without_swapping_data(int, int);
};
void linkedlist::insertatbegin(int data)
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
void linkedlist::insertatlast(int data)
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
void linkedlist::insertatlocation(int data,int p)
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
	
	else if(p == 1)
	{
		temp->next = head;
		head=temp;
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
void linkedlist::display()
{
	node *ptr=head;
	int count=0;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<endl;
		ptr=ptr->next;
		count++;
	}
	cout<<"Length of linked list: "<<count<<endl;
}
int linkedlist::delete_firstnode()
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
int linkedlist::delete_lastnode()
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
int linkedlist::delete_intermediatenode(int pos)
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
		for(int i=1;i<=pos-1 && ptr; i++)
		{
			prev=ptr;
			ptr=ptr->next;
			count++;
		}
		if(ptr)
		{
			prev->next=ptr->next;
			int del_data=ptr->data;
			free(ptr);
			return del_data;
		}
		cout<<"Wrong Position"<<endl;
		return 0;
		
	}
}

void linkedlist::delete_linkedlist()
{
	node *current,*ptr;
	current = head;
	while(current!=NULL)
	{
		ptr=current;
		current=current->next;
		free(ptr);
	}
	head=NULL;
}

void linkedlist::search_element(int x)
{
	node *ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->data==x)
		{
			cout<<"Element Found"<<endl;
			return;
		}
		ptr=ptr->next;	
	}
	cout<<"Element not Found"<<endl;
}

void linkedlist::get_node(int pos)
{
	node *ptr=head;
	int k=1;
	if(head==NULL)
	{
		cout<<"No list found"<<endl;
		return;
	}
	while(ptr!=NULL && k<pos)
	{
		k++;
		ptr=ptr->next;
	}
	if(k==pos)
	{
		cout<<ptr->data<<endl;
		return;
	}
	else
	{
		cout<<"Wrong position"<<endl;
		return;
	}
}

void linkedlist::get_node_from_end(int pos)
{	
	node *ptr=head;
	int k=1,count=0;
	if(head==NULL)
	{
		cout<<"No list found"<<endl;
		return;
	}
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->next;
	}
	k=count-pos;
	ptr=head;
	pos=1;
	while(ptr!=NULL && pos<k)
	{
		pos++;
		ptr=ptr->next;
	}
	if(k==pos)
	{
		cout<<ptr->data<<endl;
		return;
	}
	else
	{
		cout<<"Wrong position"<<endl;
		return;
	}
}
void linkedlist::middle_element()
{
	node *fast_ptr,*slow_ptr;
	fast_ptr=slow_ptr=head;
	while(fast_ptr!=NULL && fast_ptr->next!=NULL)
	{
		fast_ptr=fast_ptr->next->next;
		slow_ptr=slow_ptr->next;
	}
	cout<<slow_ptr->data<<endl;
}

void linkedlist::count_given_key(int key)
{
	node *ptr=head;
	int count = 0;
	if(head!=NULL)
	{
		while(ptr!=NULL)
		{
			if(ptr->data==key)
				count++;
			ptr=ptr->next;
		}
		cout<<count<<endl;
	}
}

bool linkedlist::detect_loop()
{
	node *fast_ptr,*slow_ptr;
	fast_ptr=slow_ptr=head;
	int count=1,b=0;
	while(fast_ptr!=NULL && fast_ptr->next!=NULL)
	{
		fast_ptr=fast_ptr->next->next;
		slow_ptr=slow_ptr->next;
		if(b==0)
		{
			if(fast_ptr==slow_ptr)
			{
				b=1;
				continue;
			}
			continue;			
		}
		
		if(b==1)
		{
			if(fast_ptr==slow_ptr)
			{
				cout<<"Length of loop: "<<count<<endl;
				return true;
			}
			count++;
		}
	}
	return false;
}

bool linkedlist::IsPalindrome()
{
	node *ptr=head;
	stack<int>s;
	while(ptr!=NULL)
	{
		s.push(ptr->data);
		ptr=ptr->next;
	}
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->data!=s.top())
			return false;
		ptr=ptr->next;
		s.pop();
	}
	return true;
}

void linkedlist::delete_duplicates_from_sortedll()
{
	node *current,*ptr;
	current=head;
	if(head==NULL)
		return;
	while(current->next!=NULL)
	{
		if(current->data==current->next->data)
		{
			ptr=current->next->next;
			free(current->next);
			current->next=ptr;
		}
		else
		{
			current=current->next;
		}
	}
}

void linkedlist::swap_nodes_without_swapping_data(int x, int y)
{
	node *current_x,*current_y,*prev_x=NULL,*prev_y=NULL;
	int flag_x,flag_y;
	flag_x=flag_y=0;
	current_x=current_y=head;
	if(head==NULL)
		return;
	if(x == y)
		return;
	while(current_x && current_x->data!=x)
	{
		prev_x=current_x;
		current_x=current_x->next;
		flag_x=1;
	}
	while(current_y && current_y->data!=y)
	{
		prev_y=current_y;
		current_y=current_y->next;
		flag_y=1;
	}
	if(flag_x != 1 && flag_y != 1)
		return;
	if (prev_x != NULL)
       prev_x->next = current_y;
   else 
       head = current_y;
   if (prev_y != NULL)
       prev_y->next = current_x;
   else
       head = current_x;
   node *temp = current_y->next; 
   current_y->next = current_x->next;
   current_x->next  = temp;
}

int main()
{
	int ch,data,pos,key,x,y;
	linkedlist l;
	while(1)
	{
		cout<<"\n**** MENU ****"<<endl;
        cout<<"1:INSERT_AT_BEGIN\n2:INDERT_AT_LAST\n3:INSERT_AT_LOCATION\n4:DELETE_FIRST_NODE\n5:DELETE_LASTNODE\n6:DELETE_INTERMEDIATENODE\n7:DISPLAY\n8:DELETE LINKED LIST \n9:SEARCH_ELEMENT\n10:GET_NODE\n11:GET NODE FROM END\n12:GET_MIDDLE_ELEMENT\n13:COUNT_GIVEN_KEY\n14:DETECT_LOOP\n15:CHECK_IF_PALINDROME\n16:DELETE_DUPLICATE_FROM_SORTED_LINKED_LIST\n17:SWAP_NODES_WITHOUT_SWAPPING_DATA\n18:EXIT\n";
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
        	case 8: l.delete_linkedlist();
        		break;
        	case 9: cin>>data;
        		l.search_element(data);
        		break;
        	case 10: cin>>pos;
        		 l.get_node(pos);
        		 break;

        	case 11: cin>>pos;
        		 l.get_node_from_end(pos);
        		 break;
        	case 12: l.middle_element();
        	         break;
        	case 13: cin>>key;
        			 l.count_given_key(key);
        			 break;
        	case 14: if(l.detect_loop())
        				cout<<"Loop Found"<<endl;
        			 else
        			 	cout<<"Loop not Found"<<endl;
        			 break;
        	case 15: if(l.IsPalindrome())
        				cout<<"Is Palindrome"<<endl;
        			 else
        			 	cout<<"Not Palindrome"<<endl;
        			 break;
        	case 16: l.delete_duplicates_from_sortedll();
        			 break;
        	case 17: cin>>x>>y;
        			 l.swap_nodes_without_swapping_data(x,y);
        			 break;
        	case 18: return 0;
        }
	}
	return 0;
}
