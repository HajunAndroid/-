#include<iostream>
using namespace std;

template<class T>
class Queue
{
public:
	int front;
	int rear;
	int size;
	T* values;
	Queue()
	{
		front = 0;
		rear = 0;
		size = 100;
		values = new T[size];
	}
	~Queue()
	{
		delete[]values;
	}
	bool isFull()
	{
		if ((rear + 1) % size == front)return true;
		return false;
	}
	bool Empty()
	{
		if (front == rear)return true;
		return false;
	}
	void push(T value)
	{
		if (!isFull()) {
			values[rear] = value;
			rear = (rear + 1) % size;
		}
	}
	void pop()
	{
		if (!Empty()) {
			front = (front + 1) % size;
		}
	}
	T Front()
	{
		return values[front];
	}
};
int main()
{
	Queue<int>q;
	q.push(1);
	q.push(2);
	q.push(3);
	int temp = q.Front();
	cout << temp << endl;
	q.pop();
	temp = q.Front();
	cout << temp << endl;
	return 0;
}