#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node *next;
};
class Queue
{
	node *front,*rear;
public:
	Queue()
	{
		front = NULL;
		rear = NULL;
	}
	void enqueue(int);
	int dequeue();
	void display();
};

void Queue::enqueue(int x)
{
	node *temp = new node;
	temp->data = x;
	temp->next = NULL;
	if(front == NULL)
	{
		front = temp;
		rear = temp;
	}
	else
	{
		rear->next = temp;
		rear = temp;
	}
}

int Queue::dequeue()
{
	int x = -1;
	
	if(front == NULL)
	{
		cout<<"No queue found"<<endl;
		return x;
	}
	node *p = front;
	front = front->next;
	x = p->data;
	free(p);
	return x;
}

void Queue::display()
{
	node *p = front;
	while(p!=NULL)
	{
		cout<<p->data<<endl;
		p = p->next;
	}
}

int main(int argc, char const *argv[])
{
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);
	q.dequeue();
	q.dequeue();
	q.display();
	return 0;
}