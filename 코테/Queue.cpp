#include<iostream>
#define MAX 101
using namespace std;

template<typename T>
class Queue
{
public:
	int front;
	int rear;
	int size;
	T* values;
	Queue()
	{
		size = MAX;
		values = new T[size];
		front = 0;
		rear = 0;
	}
	~Queue()
	{
		delete[]values;
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
		if (!empty())
			front = (front + 1) % size;
	}
	bool empty()
	{
		if (rear == front)
			return true;
		else
			return false;
	}
	bool isFull()
	{
		if ((rear + 1) % size == front)
			return true;
		else
			return false;
	}
};

int main()
{
	Queue<int>q;
	q.push(3);
	q.push(4);
	q.push(5);
	q.pop();
	q.pop();
	q.pop();
	int temp = q.values[q.front];
	cout << temp;
}