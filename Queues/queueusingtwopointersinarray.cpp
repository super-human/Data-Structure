#include<bits/stdc++.h>
using namespace std;

class Queue
{
	int front;
	int rear;
	int size;
	int *q;
public:
	Queue(int size)
	{
		front = rear = -1;
		this->size = size;
		q = new int[this->size];
	}
	void enqueue(int);
	int dequeue();
	void display();
};

void Queue::enqueue(int data)
{
	if(rear == size - 1)
		cout<<"Queue is full"<<endl;
	else
		q[++rear] = data;
}

int Queue::dequeue()
{
	int x = -1;
	if(front == rear)
		cout<<"Queue is empty"<<endl;
	else
		x = q[++front];
	return x;
}

void Queue::display()
{
	for (int i = front+1; i <= rear; ++i)
		cout<<q[i]<<" ";
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	Queue q(5);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	cout<<q.dequeue();
	q.display();
	return 0;
}
