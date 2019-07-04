#include<bits/stdc++.h>
using namespace std;

class CircularQueue
{
	int size;
	int front;
	int rear;
	int *q;
public:
	CircularQueue(int size)
	{
		this->size = size;
		front = 1;
		rear = 1;
		q = new int[this->size];
	}
	void enqueue(int);
	int dequeue();
	void display();
};
void CircularQueue::enqueue(int x)
{
	if((rear+1)%size == front)
		cout<<"Queue is full"<<endl;
	else
	{
		rear = (rear+1)%size;
		q[rear] = x;
	}
}

int CircularQueue::dequeue()
{
	int x = -1;
	if(front == rear)
		cout<<"Queue is empty"<<endl;
	else
	{
		front = (front + 1)%size;
		x = q[front];
	}
	return x;
}

void CircularQueue::display()
{
	int i = front + 1;
	do
	{
		cout<<q[i]<<endl;
		i = (i+1) % size;
	}while(i != (rear + 1)%size);
	cout<<"\n";
}

int main(int argc, char const *argv[])
{
	CircularQueue q(5);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	q.enqueue(50);
	q.enqueue(60);
	q.display();
	return 0;
}
